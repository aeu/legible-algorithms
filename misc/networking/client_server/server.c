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

    printf("server starting\n");

    int server_socket = socket(AF_INET,SOCK_STREAM,0); // , bind(), listen(), accept(), read(), write()

    struct sockaddr_in server_addr;
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
        printf("bind passed, lets listen now\n");
        listen(server_socket, SOMAXCONN);

        for (;;) 
        {
            struct sockaddr client_addr;
            socklen_t client_address_length = sizeof(client_addr);
            int client_fd = accept(server_socket, (struct sockaddr *)&client_addr, &client_address_length);

            if (client_fd < 0) {
                perror("accept");
                continue;
            }

            int *pclient = malloc(sizeof(int));
            *pclient = client_fd;

            pthread_t tid;
            pthread_create(&tid, NULL, worker, pclient);
            pthread_detach(tid);
        }
    }
    return 0;
}
