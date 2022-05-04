#include "Outputer.h"

using namespace std;

namespace outputs // Looks like always encapsolating the .cpp file in the same namespace as the .h file is the way to go (to avoid linking errors).
{
    ostream &operator<<(ostream &os, const outputs::Outputer &outputer)
    {
        return os << "Hello " + outputer.value + "!" << endl;
    }

    Outputer::Outputer(string value, string value2) : value(value), value2(value2)
    {
    }

    string &Outputer::getValue()
    {
        return this->value;
    }

};
