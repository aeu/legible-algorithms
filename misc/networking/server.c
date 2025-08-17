// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
        struct sockaddr client_addr;
        unsigned int client_address_length = sizeof( client_addr );
        int client_fd = accept(server_socket, (struct sockaddr *)&client_addr, &client_address_length);
        if( client_fd != -1 )
        {
            for(;;)
            {
                char buffer[1024];
                int readres = read(client_fd, buffer, sizeof(buffer));
                if( readres == 0)
                {
                    printf("Client disconnected\n");
                    break;
                }
                else if( readres > 0 )
                {
                    buffer[readres] = '\0';
                    printf("%s", buffer);
                }
                else
                {
                    printf("read error\n");
                }
            }
        }
        close( client_fd );
        close( server_socket );
    }
    return 0;
}
        
