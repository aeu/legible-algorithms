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


// This structure defines the task that the worker thread is going to perform.  
// The max interval is the maximum time between messages sent but to make it
// intersting it will be a random time up to that.
typedef struct {
    int max_interval;
    int port;
    char *address;
    char *task_name;

} TaskDefinition;

typedef struct {
    int total_message_count;
    pthread_mutex_t count_mutex;
} SharedData;

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

    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if( client_socket < 0 ) 
    {
        printf("error getting socket\n");
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(td->port);
    inet_pton(AF_INET, td->address, &server_addr.sin_addr);
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("we had some kind of error\n");
    }
    else
    {
        char buffer[1024];
        for(;;)
        {
            fgets(buffer,sizeof(buffer), stdin);
            write( client_socket, buffer, sizeof( buffer));
            if( buffer[0] == 'q')
                break; 
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

    pthread_join(threads[0], NULL);
    pthread_mutex_destroy(&shared_data.count_mutex);

    printf("exiting\n");
    return 0;
}
