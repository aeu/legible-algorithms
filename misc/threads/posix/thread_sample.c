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
    pthread_mutex_t print_mutex;
    pthread_mutex_t work_mutex;
    pthread_mutex_t state_mutex;
    pthread_cond_t  condition_variable;
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
    pthread_mutex_lock(&shared_data->print_mutex);
    printf("%s", message);
    pthread_mutex_unlock(&shared_data->print_mutex);
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
        pthread_mutex_lock(&shared_data->work_mutex);
        shared_data->work_units += 1;
        int total = shared_data->work_units;
        pthread_mutex_unlock(&shared_data->work_mutex);
        sprintf( &message[0], "[%.3f] %s: progress, total work units = %d\n", now_sec(), task->name, total);
        safe_printf(shared_data, message );
    }

    sprintf( &message[0], "[%.3f] %s: done\n", now_sec(), task->name);
    safe_printf(shared_data, message );

    // Mark done and signal
    pthread_mutex_lock(&shared_data->state_mutex);
    shared_data->done[task->idx] = 1;
    pthread_cond_broadcast(&shared_data->condition_variable);
    pthread_mutex_unlock(&shared_data->state_mutex);

    return (void*)(uintptr_t)task->seconds; // return "work units"
}

int main(void) 
{
    pthread_t threads[3];
    Task tasks[3] = {
        { "T1", 3, 0 },
        { "T2", 1, 1 },
        { "T3", 2, 2 }
    };
    void *ret = NULL;
    char message[255];

    SharedData shared_data;
    pthread_mutex_init(&shared_data.print_mutex, NULL);
    pthread_mutex_init(&shared_data.work_mutex,  NULL);
    pthread_mutex_init(&shared_data.state_mutex, NULL);
    pthread_cond_init (&shared_data.condition_variable,  NULL);
    shared_data.work_units = 0;
    for (int i = 0; i < 3; i++) 
    { 
        shared_data.done[i]   = 0; 
        shared_data.joined[i] = 0; 
    }
    shared_data.remaining = 3;

    struct { Task *t; SharedData *shared_data; } args[3] = 
    {
        { &tasks[0], &shared_data }, 
        { &tasks[1], &shared_data }, 
        { &tasks[2], &shared_data }
    };

    double t0 = now_sec();
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    // Wait-and-join loop: wait until any thread marks itself done, then join it.
    while (shared_data.remaining > 0) 
    {
        pthread_mutex_lock(&shared_data.state_mutex);

        // Wait until at least one unjoined thread is marked done.
        int have_joinable = 0;
        for (int i = 0; i < 3; i++)
        {
            if (shared_data.done[i] && !shared_data.joined[i]) 
            { 
                have_joinable = 1; 
                break; 
            }
        }
        while (!have_joinable) 
        {
            pthread_cond_wait(&shared_data.condition_variable, &shared_data.state_mutex);
            for (int i = 0; i < 3; i++)
            {
                if( shared_data.done[i] && ! shared_data.joined[i] ) 
                { 
                    have_joinable = 1; 
                    break; 
                }
            }
        }
        // Join all that are done but not yet joined.
        for (int i = 0; i < 3; i++) 
        {
            if (shared_data.done[i] && !shared_data.joined[i]) 
            {
                shared_data.joined[i] = 1;
                pthread_mutex_unlock(&shared_data.state_mutex);

                pthread_join(threads[i], &ret);
                sprintf(&message[0], "[%.3f] <main> %s - joined (ret=%ld)\n", now_sec(), tasks[i].name, (long)ret);
                safe_printf(&shared_data, message );
                pthread_mutex_lock(&shared_data.state_mutex);
                shared_data.remaining--;
            }
        }
        pthread_mutex_unlock(&shared_data.state_mutex);
    }

    pthread_mutex_lock(&shared_data.work_mutex);
    int final_total = shared_data.work_units;
    pthread_mutex_unlock(&shared_data.work_mutex);

    sprintf( &message[0], "[%.3f] <main> all joined, total=%d, elapsed ~%.3fs\n", now_sec(), final_total, now_sec() - t0);
    safe_printf(&shared_data, message );

    pthread_mutex_destroy(&shared_data.print_mutex);
    pthread_mutex_destroy(&shared_data.work_mutex);
    pthread_mutex_destroy(&shared_data.state_mutex);
    pthread_cond_destroy (&shared_data.condition_variable);

    return 0;
}
