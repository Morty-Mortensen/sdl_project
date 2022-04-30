#include <iostream>
#include <vector>
#include <string>
#include "network/Consumer.h"
#include "network/Producer.h"

using namespace std;
using namespace network;

int main(int argc, char *argv[])
{
    cout << "Hello World" << endl;
    Consumer consumer;
    Producer producer;

    int serverFd = consumer.socket();
    consumer.bind(serverFd);
    consumer.listen(serverFd);
    consumer.accept(serverFd);

    int clientSocket = producer.socket();
    producer.connect(clientSocket);
}