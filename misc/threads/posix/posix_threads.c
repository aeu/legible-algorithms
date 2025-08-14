// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

#define NUM_THREADS 3

typedef struct {
    const char *name;
    int seconds;
    int index;
} Task;


typedef struct {
    pthread_mutex_t print_mutex;
    pthread_mutex_t work_mutex;
    pthread_mutex_t state_mutex;
    pthread_cond_t  condition_variable;
    int work_units;

    // per-thread state
    int done[NUM_THREADS];
    int joined[NUM_THREADS];
    int remaining;
} SharedData;

static double now_sec(void) 
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

/**
 * thread safe printing.  We pass in the shared data structure which
 * contains the print mutex, and we pass in the message to be printed.
 * Only sends to the output stream if it can get a lock on the mutex.
 *
 */
static void mutexed_printf(SharedData *shared_data, const char *message) 
{
    pthread_mutex_lock(&shared_data->print_mutex);
    printf("%s", message);
    pthread_mutex_unlock(&shared_data->print_mutex);
}

/**
 * per posix threads model, this takes a void * pointer as argument
 * data.  We are using an anonymous structure to pass in the Task
 * definition as well as the shared data.
 */
void *worker(void *arg) 
{
    struct { Task *task; SharedData *shared_data; } *in = arg;
    Task       *task = in->task;
    SharedData *shared_data = in->shared_data;

    char message[255];
    snprintf( &message[0], sizeof message, "[%2.3f] %s: start (work %ds)\n", now_sec(), task->name, task->seconds);
    mutexed_printf(shared_data, message);

    for (int i = 0; i < task->seconds; i++) 
    {
        sleep(1);
        pthread_mutex_lock(&shared_data->work_mutex);
        shared_data->work_units += 1;
        int total = shared_data->work_units;
        pthread_mutex_unlock(&shared_data->work_mutex);
        // notice that we took a copy of the total work units to be
        // used later after we give up the mutex.  This is to make
        // sure we block other threads as little as possible.
        snprintf( &message[0], sizeof message, "[%.3f] %s: progress, total work units = %d\n", now_sec(), task->name, total);
        mutexed_printf(shared_data, message );
    }

    snprintf( &message[0], sizeof message, "[%.3f] %s: done\n", now_sec(), task->name);
    mutexed_printf(shared_data, message );

    // Here we mark the task for this worker as being done, and we
    // also do a broadcast on the condition variable to tell others

    pthread_mutex_lock(&shared_data->state_mutex);
    shared_data->done[task->index] = 1;
    pthread_cond_broadcast(&shared_data->condition_variable);
    pthread_mutex_unlock(&shared_data->state_mutex);

    return (void*)(uintptr_t)task->seconds; // return "work units"
}

int main(int argc, char **argv) 
{
    pthread_t threads[NUM_THREADS];
    Task tasks[NUM_THREADS] = {
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
    for (int i = 0; i < NUM_THREADS; i++) 
    { 
        shared_data.done[i]   = 0; 
        shared_data.joined[i] = 0; 
    }
    shared_data.remaining = NUM_THREADS;

    struct { Task *task; SharedData *shared_data; } args[NUM_THREADS] = 
    {
        { &tasks[0], &shared_data }, 
        { &tasks[1], &shared_data }, 
        { &tasks[2], &shared_data }
    };

    double t0 = now_sec();
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    // Wait-and-join loop: wait until any thread marks itself done, then join it.
    while (shared_data.remaining > 0) 
    {
        pthread_mutex_lock(&shared_data.state_mutex);

        // Wait until at least one unjoined thread is marked done.
        int have_joinable = 0;
        for (int i = 0; i < NUM_THREADS; i++)
        {
            if (shared_data.done[i] && !shared_data.joined[i]) 
            { 
                have_joinable = 1; 
                break; 
            }
        }
        while (!have_joinable) 
        {
	    // conditional wait on the condition variable, also pass in the state
	    // mutex which is needed by cond wait.   At this point the state mutex
	    // is released (because this thread is waiting).  When the condition
	    // variable hits, the state mutex will be locked again and execution
	    // will continue

            pthread_cond_wait(&shared_data.condition_variable, &shared_data.state_mutex);
            for (int i = 0; i < NUM_THREADS; i++)
            {
                if( shared_data.done[i] && ! shared_data.joined[i] ) 
                { 
                    have_joinable = 1; 
                    break; 
                }
            }
        }
        // Join all that are done but not yet joined.
        for (int i = 0; i < NUM_THREADS; i++) 
        {
            if (shared_data.done[i] && !shared_data.joined[i]) 
            {
                shared_data.joined[i] = 1;
                pthread_mutex_unlock(&shared_data.state_mutex);

                pthread_join(threads[i], &ret);
                snprintf(&message[0], sizeof message,  "[%.3f] <main> %s - joined (ret=%ld)\n", now_sec(), tasks[i].name, (long)ret);
                mutexed_printf(&shared_data, message );
                pthread_mutex_lock(&shared_data.state_mutex);
                shared_data.remaining--;
            }
        }
        pthread_mutex_unlock(&shared_data.state_mutex);
    }

    pthread_mutex_lock(&shared_data.work_mutex);
    int final_total = shared_data.work_units;
    pthread_mutex_unlock(&shared_data.work_mutex);

    snprintf( &message[0], sizeof message, "[%.3f] <main> all joined, total=%d, elapsed ~%.3fs\n", now_sec(), final_total, now_sec() - t0);
    mutexed_printf(&shared_data, message );

    pthread_mutex_destroy(&shared_data.print_mutex);
    pthread_mutex_destroy(&shared_data.work_mutex);
    pthread_mutex_destroy(&shared_data.state_mutex);
    pthread_cond_destroy (&shared_data.condition_variable);

    return 0;
}
