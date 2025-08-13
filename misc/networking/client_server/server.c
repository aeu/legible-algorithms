// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>


void *worker(void *arg) 
{
    int client_fd = *(int *)arg;
    free(arg);

    char buffer[1024];
    for (;;) {
        int readres = read(client_fd, buffer, sizeof(buffer) - 1);
        if (readres <= 0) {
            printf("Client disconnected or error\n");
            break;
        }
        buffer[readres] = '\0';
        printf("%s", buffer);
    }
    close(client_fd);
    return NULL;
}



int main(int argc, char **argv)
{
    if( argc > 0 )
        printf("%s\n",argv[0]);

    printf("Server starting\n");

    // create the socket
    int server_socket = socket(AF_INET,SOCK_STREAM,0); // , bind(), listen(), accept(), read(), write()

    // define the server address as any address, and port 51000.  Note
    // also that we 0 initialize the structure just because this is
    // good practice to do anyway.

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(51000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("we had some kind of error\n");
    }
    else
    {
        printf("bind() passed, start listening\n");
        // start listening on the socket.  The second argument is the
        // max number of connections we are allowing to be queued up,
        // which (as of now) is a constant defined as 128
        listen(server_socket, SOMAXCONN);

        // start our forever loop where we accept incoming
        // connections.  When we get one, pass it off to a worker
        // thread.  Note that this is not how we would do it in
        // production systems as it doesn't scale very well.  For that
        // we would use epoll or similar.
        for (;;) 
        {
            struct sockaddr client_addr;
            socklen_t client_address_length = sizeof(client_addr);
            int client_fd = accept(server_socket, (struct sockaddr *)&client_addr, &client_address_length);

            if (client_fd < 0) {
                perror("accept");
                continue;
            }

            // setup for the creation and spawning of the worker thread.
            int *pclient = malloc(sizeof(int));
            *pclient = client_fd;
            pthread_t tid;
            pthread_create(&tid, NULL, worker, pclient);
            pthread_detach(tid);
        }
    }
    return 0;
}
