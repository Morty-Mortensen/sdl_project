// #include <iostream>
#include <vector>
#include <string>
#include "network/Consumer.h"
#include "network/Producer.h"
#include "outputs/Outputer.h"
#include "files/Reader.h"

using namespace std;
using namespace network;

int main(int argc, char *argv[])
{

    files::Reader reader{"assets/input.txt"};

    // vector<string> vec = {"Cool first line", "Cool second line", "cool third line"};
    // reader.writeFile(vec);

    const vector<string> vec = reader.readFile<string>();

    for (const string value : vec)
    {
        cout << value << endl;
    }

    // outputs::Outputer outputer("test1", "test2");

    // cout << outputer;

    // string &value = outputer.getValue();
    // cout << value << endl;
    // value += " - Am I your friend?";
    // cout << outputer;

    // cout << "Hello World" << endl;
    // Consumer consumer;
    // Producer producer;

    // int serverFd = consumer.socket();
    // consumer.bind(serverFd);
    // consumer.listen(serverFd);
    // consumer.accept(serverFd);

    // int clientSocket = producer.socket();
    // producer.connect(clientSocket);
}