#include "Producer.h"
using namespace std;

namespace network
{
    Producer::Producer()
    {
        this->address.sin_family = AF_INET;
        this->address.sin_port = htons(PORT);
    }

    int Producer::socket()
    {
        int socket = 0;
        if ((socket = ::socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("\n Socket creation error \n");
            return -1;
        }

        // Convert IPv4 and IPv6 addresses from text to binary
        // form
        if (::inet_pton(AF_INET, "127.0.0.1", &this->address.sin_addr) <= 0)
        {
            cerr << "Invalid address/ Address not supported" << endl;
            return -1;
        }

        return socket;
    }

    void Producer::connect(int socket)
    {
        if (::connect(socket, (struct sockaddr *)&this->address,
                      sizeof(this->address)) < 0)
        {
            cerr << "nConnection Failed" << endl;
        }
    }
};
