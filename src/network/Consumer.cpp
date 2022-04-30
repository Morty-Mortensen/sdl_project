#include "Consumer.h"

using namespace network;
using namespace std;

Consumer::Consumer()
{
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(PORT);
}

int Consumer::socket()
{
    int serverFd;
    // Creating socket file descriptor
    if ((serverFd = ::socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        cerr << "socket failed";
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(serverFd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)))
    {
        cerr << "setsockopt";
        exit(EXIT_FAILURE);
    }

    return serverFd;
}

void Consumer::bind(int serverFd)
{
    if (::bind(serverFd, (struct sockaddr *)&this->address,
               sizeof(this->address)) < 0)
    {
        cerr << "bind failed";
        exit(EXIT_FAILURE);
    }
}

void Consumer::listen(int serverFd)
{
    if (::listen(serverFd, 3) < 0)
    {
        cerr << "listen";
        exit(EXIT_FAILURE);
    }
}

int Consumer::accept(int serverFd)
{
    int newSocket;
    if ((newSocket = ::accept(serverFd, (struct sockaddr *)&this->address,
                              (socklen_t *)&this->addressLength)) < 0)
    {
        cerr << "accept";
        exit(EXIT_FAILURE);
    }

    return newSocket;
}

int Consumer::read(int socket, char buffer[1024])
{
    int valRead = ::read(socket, buffer, 1024);
    return valRead;
}

void Consumer::write(int socket, char *message)
{
    ::send(socket, message, strlen(message), 0);
}
