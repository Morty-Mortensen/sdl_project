#include <iostream>
#include <vector>
#include <string>
#include "network/Consumer.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World" << endl;
    network::Consumer test;

    test.listen();
}