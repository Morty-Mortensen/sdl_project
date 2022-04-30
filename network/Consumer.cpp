#include "Consumer.h"
#include <iostream>

using namespace network;
using namespace std;

Consumer::Consumer()
{
    cout << "Initialized a Consumer!" << endl;
}

void Consumer::socket()
{
    cout << "Socket" << endl;
}

void Consumer::bind()
{
    cout << "Bind" << endl;
}

void Consumer::listen()
{
    cout << "Listening" << endl;
}

void Consumer::accept()
{
    cout << "Accept" << endl;
}

void Consumer::read()
{
    cout << "Read" << endl;
}

void Consumer::write()
{
    cout << "Write" << endl;
}
