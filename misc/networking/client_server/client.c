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

int main(int argc, char **argv)
{
    if( argc > 0 )
        printf("%s\n",argv[0]);

    printf("client starting\n");

    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if( client_socket < 0 ) 
    {
        printf("error getting socket\n");
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(51000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
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
