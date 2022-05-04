#ifndef OUTPUTER_H
#define OUTPUTER_H
#include <iostream> // Controls formatting of input and output
#include <string>
// <ios>
// <istream>
// <ostream>
// <iomanip>

namespace outputs
{
    enum OutputOption
    {
        DECIMAL,
        HEX,
        OCT,
        SCIENTIFIC
    };

    class Outputer
    {
    public:
        Outputer(std::string value, std::string value2);
        friend std::ostream &operator<<(std::ostream &os, const Outputer &outputer);
        std::string &getValue(); // Return a "read-only" reference to the private value.

    private:
        std::string value;
        std::string value2;
    };
};

#endif