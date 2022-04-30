#ifndef PRODUCER_H
#define PRODUCER_H
#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

// Client

namespace network
{
    class Producer
    {
    public:
        Producer();
        int socket();
        void connect(int socket);

    private:
        sockaddr_in address;
    };
};

#endif