#ifndef CONSUMER_H
#define CONSUMER_H
#include <netinet/in.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

// Server

namespace network
{
    class Consumer
    {
    public:
        Consumer();
        int socket();
        void bind(int serverFd);
        void listen(int serverFd);
        int accept(int serverFd);
        int read(int newSocket, char buffer[1024]);
        void write(int socket, char *message);

    private:
        sockaddr_in address;
        int addressLength = sizeof(address);
    };
};

#endif
