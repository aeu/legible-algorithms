#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

typedef struct {
    const char *name;
    int seconds;
    int idx;
} Task;

typedef struct {
    pthread_mutex_t print_mtx;
    pthread_mutex_t work_mtx;
    pthread_mutex_t state_mtx;
    pthread_cond_t  state_cv;
    int work_units;

    // per-thread state
    int done[3];
    int joined[3];
    int remaining;
} SharedData;

static double now_sec(void) 
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

static void safe_printf(SharedData *shared_data, const char *message) 
{
    pthread_mutex_lock(&shared_data->print_mtx);
    printf("%s", message);
    pthread_mutex_unlock(&shared_data->print_mtx);
}

void* worker(void *arg) 
{
    struct { Task *task; SharedData *shared_data; } *in = arg;
    Task   *task = in->task;
    SharedData *shared_data = in->shared_data;

    char message[255];
    sprintf( &message[0], "[%2.3f] %s: start (work %ds)\n", now_sec(), task->name, task->seconds);
    safe_printf(shared_data, message);

    for (int i = 0; i < task->seconds; i++) 
    {
        sleep(1);
        pthread_mutex_lock(&shared_data->work_mtx);
        shared_data->work_units += 1;
        int total = shared_data->work_units;
        pthread_mutex_unlock(&shared_data->work_mtx);
        sprintf( &message[0], "[%.3f] %s: progress, total work units = %d\n", now_sec(), task->name, total);
        safe_printf(shared_data, message );
    }

    sprintf( &message[0], "[%.3f] %s: done\n", now_sec(), task->name);
    safe_printf(shared_data, message );

    // Mark done and signal
    pthread_mutex_lock(&shared_data->state_mtx);
    shared_data->done[task->idx] = 1;
    pthread_cond_broadcast(&shared_data->state_cv);
    pthread_mutex_unlock(&shared_data->state_mtx);

    return (void*)(uintptr_t)task->seconds; // return "work units"
}

int main(void) 
{
    pthread_t threads[3];
    Task tasks[3] = {
        { "Strawberry", 3, 0 },
        { "Chocolate", 1, 1 },
        { "Vanilla", 2, 2 }
    };
    void *ret = NULL;
    char message[255];

    SharedData S;
    pthread_mutex_init(&S.print_mtx, NULL);
    pthread_mutex_init(&S.work_mtx,  NULL);
    pthread_mutex_init(&S.state_mtx, NULL);
    pthread_cond_init (&S.state_cv,  NULL);
    S.work_units = 0;
    for (int i = 0; i < 3; i++) 
    { 
        S.done[i]=0; 
        S.joined[i]=0; 
    }
    S.remaining = 3;

    struct { Task *t; SharedData *S; } args[3] = 
    {
        { &tasks[0], &S }, { &tasks[1], &S }, { &tasks[2], &S }
    };

    double t0 = now_sec();
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    // Wait-and-join loop: wait until any thread marks itself done, then join it.
    while (S.remaining > 0) 
    {
        pthread_mutex_lock(&S.state_mtx);

        // Wait until at least one unjoined thread is marked done.
        int have_joinable = 0;
        for (int i = 0; i < 3; i++)
        {
            if (S.done[i] && !S.joined[i]) 
            { 
                have_joinable = 1; 
                break; 
            }
        }
        while (!have_joinable) 
        {
            pthread_cond_wait(&S.state_cv, &S.state_mtx);
            for (int i = 0; i < 3; i++)
            {
                if (S.done[i] && !S.joined[i]) 
                { 
                    have_joinable = 1; 
                    break; 
                }
            }
        }
        // Join all that are done but not yet joined.
        for (int i = 0; i < 3; i++) 
        {
            if (S.done[i] && !S.joined[i]) 
            {
                S.joined[i] = 1;
                pthread_mutex_unlock(&S.state_mtx);

                pthread_join(threads[i], &ret);
                sprintf( &message[0], "[%.3f] <main> %s - joined (ret=%ld)\n", now_sec(), tasks[i].name, (long)ret);
                safe_printf(&S, message );
                pthread_mutex_lock(&S.state_mtx);
                S.remaining--;
            }
        }
        pthread_mutex_unlock(&S.state_mtx);
    }

    pthread_mutex_lock(&S.work_mtx);
    int final_total = S.work_units;
    pthread_mutex_unlock(&S.work_mtx);

    sprintf( &message[0], "[%.3f] <main> all joined, total=%d, elapsed ~%.3fs\n", now_sec(), final_total, now_sec() - t0);
    safe_printf(&S, message );

    pthread_mutex_destroy(&S.print_mtx);
    pthread_mutex_destroy(&S.work_mtx);
    pthread_mutex_destroy(&S.state_mtx);
    pthread_cond_destroy (&S.state_cv);

    return 0;
}
