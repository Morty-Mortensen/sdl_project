#ifndef CONSUMER_H
#define CONSUMER_H

// #include <netinet/in.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <unistd.h>
// #define PORT 8080

namespace network
{
    class Consumer
    {
    public:
        Consumer();
        void socket();
        void bind();
        void listen();
        void accept();
        void read();
        void write();

    private:
    };
};

#endif
