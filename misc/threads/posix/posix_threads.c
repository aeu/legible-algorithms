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
    // the print mutex gatekeeps access to the console so that multiple
    // threads aren't printing at the same time.
    pthread_mutex_t print_mutex;
    // the work mutex gatekeeps acccess to the variable that tracks the work
    // that is being done by the thread, to avoid a race condition
    pthread_mutex_t work_mutex;
    // the state mutex is used by the condintional wait
    pthread_mutex_t state_mutex;
    // and the actual condition variable we are keying off of
    pthread_cond_t  condition_variable;
    int work_units;

    // per-thread state
    int done[NUM_THREADS];
    int joined[NUM_THREADS];
    int remaining;
} WorkerArgs;

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
static void mutexed_printf(WorkerArgs *worker_args, const char *message)
{
    pthread_mutex_lock(&worker_args->print_mutex);
    printf("%s", message);
    pthread_mutex_unlock(&worker_args->print_mutex);
}

/**
 * per posix threads model, this takes a void * pointer as argument
 * data.  We are using an anonymous structure to pass in the Task
 * definition as well as the shared data.
 */
void *worker(void *arg)
{
    struct { Task *task; WorkerArgs *worker_args; } *in = arg;
    Task       *task = in->task;
    WorkerArgs *worker_args = in->worker_args;

    char message[255];
    snprintf( &message[0], sizeof message, "[%2.3f] %s: start (work %ds)\n", now_sec(), task->name, task->seconds);
    mutexed_printf(worker_args, message);

    for (int i = 0; i < task->seconds; i++)
    {
        sleep(1);
        // lock the work mutex because we are going to increment the
        // work units counter (which is used to track if we're done or
        // not
        pthread_mutex_lock(&worker_args->work_mutex);
        worker_args->work_units += 1;
        int total = worker_args->work_units;
        pthread_mutex_unlock(&worker_args->work_mutex);
        // notice that we took a copy of the total work units to be
        // used later after we give up the mutex.  So lock, modify,
        // copy, release.  - we don't need to have the work counter
        // locked while we print out status
        snprintf( &message[0], sizeof message, "[%.3f] %s: progress, total work units = %d\n", now_sec(), task->name, total);
        mutexed_printf(worker_args, message );
    }

    snprintf( &message[0], sizeof message, "[%.3f] %s: done\n", now_sec(), task->name);
    mutexed_printf(worker_args, message );

    // Here we mark the task for this worker as being done, and we
    // also do a broadcast on the condition variable to tell others
    // the flow is lock the state mutex, update the done array that
    // tracks thread state, and then broadcast on the condition
    // variable, which will wake every thread that is sleeping on it.
    // Then we release the state mutex (because the person waiting for
    // it is going to need it in order to check state
    pthread_mutex_lock(&worker_args->state_mutex);
    worker_args->done[task->index] = 1;
    pthread_cond_broadcast(&worker_args->condition_variable);
    pthread_mutex_unlock(&worker_args->state_mutex);

    return (void*)(uintptr_t)task->seconds; // return "work units"
}

int main(int argc, char **argv)
{
    pthread_t threads[NUM_THREADS];
    Task tasks[NUM_THREADS] = {
        // task name
        // how long its going to run
        // index into the task array.
        { "T1", 3, 0 },
        { "T2", 1, 1 },
        { "T3", 2, 2 }
    };
    void *ret = NULL;
    char message[255];

    WorkerArgs worker_args;
    pthread_mutex_init(&worker_args.print_mutex, NULL);
    pthread_mutex_init(&worker_args.work_mutex,  NULL);
    pthread_mutex_init(&worker_args.state_mutex, NULL);
    pthread_cond_init (&worker_args.condition_variable,  NULL);
    worker_args.work_units = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        worker_args.done[i]   = 0;
        worker_args.joined[i] = 0;
    }
    worker_args.remaining = NUM_THREADS;

    struct { Task *task; WorkerArgs *worker_args; } args[NUM_THREADS] =
    {
        { &tasks[0], &worker_args },
        { &tasks[1], &worker_args },
        { &tasks[2], &worker_args }
    };

    double t0 = now_sec();
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    // Wait-and-join loop: wait until any thread marks itself done, then join it.
    while (1)
    {
        pthread_mutex_lock(&worker_args.state_mutex);

        if( worker_args.remaining == 0 )
        {
            pthread_mutex_unlock(&worker_args.state_mutex);
            break;
        }

        // Wait until at least one unjoined thread is marked done.
        int have_joinable = 0;
        for (int i = 0; i < NUM_THREADS; i++)
        {
            if (worker_args.done[i] && !worker_args.joined[i])
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

            pthread_cond_wait(&worker_args.condition_variable, &worker_args.state_mutex);
            for (int i = 0; i < NUM_THREADS; i++)
            {
                if( worker_args.done[i] && ! worker_args.joined[i] )
                {
                    have_joinable = 1;
                    break;
                }
            }
        }
        // Join all that are done but not yet joined.
        for (int i = 0; i < NUM_THREADS; i++)
        {
            if (worker_args.done[i] && !worker_args.joined[i])
            {
                worker_args.joined[i] = 1;
                pthread_mutex_unlock(&worker_args.state_mutex);

                pthread_join(threads[i], &ret);
                snprintf(&message[0], sizeof message,  "[%.3f] <main> %s - joined (ret=%ld)\n", now_sec(), tasks[i].name, (long)ret);
                mutexed_printf(&worker_args, message );
                pthread_mutex_lock(&worker_args.state_mutex);
                worker_args.remaining--;
            }
        }
        pthread_mutex_unlock(&worker_args.state_mutex);
    }

    pthread_mutex_lock(&worker_args.work_mutex);
    int final_total = worker_args.work_units;
    pthread_mutex_unlock(&worker_args.work_mutex);

    snprintf( &message[0], sizeof message, "[%.3f] <main> all joined, total=%d, elapsed ~%.3fs\n", now_sec(), final_total, now_sec() - t0);
    mutexed_printf(&worker_args, message );

    pthread_mutex_destroy(&worker_args.print_mutex);
    pthread_mutex_destroy(&worker_args.work_mutex);
    pthread_mutex_destroy(&worker_args.state_mutex);
    pthread_cond_destroy (&worker_args.condition_variable);

    return 0;
}
