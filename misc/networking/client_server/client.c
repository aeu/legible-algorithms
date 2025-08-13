// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>


// This structure defines the task that the worker thread is going to perform.  
// The max interval is the maximum time between messages sent but to make it
// intersting it will be a random time up to that.
typedef struct {
    int max_interval;
    int port;
    char *address;
    char *task_name;
} TaskDefinition;

// This sample code is also meant to show mutliple clients connecting
// to the same server, so I'm creating a structure for data that is
// going to be shared between the threads, specifically the mutex and
// the total message count that has been sent cumulatively across all
// threads.

typedef struct {
    int total_message_count;
    pthread_mutex_t count_mutex;
} SharedData;

// The runtime info that is sent to the worker thread on spawn.  It
// contains the shared data structure (the mutex and the sent count)
// as well as the information that the worker thread needs to run.

typedef struct {
    SharedData *sd;
    TaskDefinition *td;
} WorkerArgs;

void *worker(void *work_args)
{
    WorkerArgs *wa = ( WorkerArgs *) work_args;
    TaskDefinition *td = wa->td;
    SharedData     *sd = wa->sd;
    printf("In the worker, connectiong %s:%d\n", td->address, td->port);

    // create the client socket
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if( client_socket < 0 ) 
    {
        printf("error getting socket\n");
        return;
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(td->port);
    inet_pton(AF_INET, td->address, &server_addr.sin_addr);
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("Error performing connect()\n");
    }
    else
    {
        char buffer[1024];
        for(;;)
        {
            int sleeptime = rand() % td->max_interval ; 
            sleep( sleeptime );
            // send the message to the server.
            write( client_socket, buffer, strlen( buffer ));

            // lock the shared mutex and update the count of total
            // messages sent across all threads.

            pthread_mutex_lock(&sd->count_mutex);
            int total_messages = sd->total_message_count++;
            pthread_mutex_unlock(&sd->count_mutex);
            snprintf(buffer,1024,"[%s] - will sleep %d before next send.  Total sent %d\n", 
                     td->task_name, 
                     sleeptime,
                     total_messages);
            printf("%s",buffer);
            
        }
        close( client_socket );
    }
    return 0;
}

#define NUM_THREADS 5

int main(int argc, char **argv)
{
    if( argc > 0 )
        printf("%s\n",argv[0]);
    pthread_t threads[NUM_THREADS];

    printf("client starting\n");

    SharedData shared_data = {0};
    pthread_mutex_init(&shared_data.count_mutex, NULL);
    shared_data.total_message_count = 0;
    TaskDefinition task_data = { 5, 51000, "127.0.0.1", "Client One" };
    WorkerArgs *worker_args = malloc( sizeof( WorkerArgs));
    worker_args->sd = &shared_data;
    worker_args->td = &task_data;
    pthread_create(&threads[0], NULL, worker, (void *)worker_args);

    TaskDefinition task_data2 = { 10, 51000, "127.0.0.1", "Client Two" };
    WorkerArgs *worker_args2 = malloc( sizeof( WorkerArgs));
    worker_args2->sd = &shared_data;
    worker_args2->td = &task_data2;
    pthread_create(&threads[1], NULL, worker, (void *)worker_args2);

    // join the threads and destroy the shared mutex
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_mutex_destroy(&shared_data.count_mutex);

    printf("exiting\n");
    return 0;
}



