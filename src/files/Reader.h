#ifndef READER_H
#define READER_H

#include <iostream> // Controls formatting of input and output
// <ios>
// <istream>
// <ostream>
// <iomanip>
#include <fstream> // File Stream
// ifstream - Reading from a file.
// ofstream - Writing to a file.
// fstreams - Reading from and writing to a file.
#include <sstream> // String Stream
// istringstream - Reading from a string.
// ostringstream - Writing to a string.
// stringstream - Reading from and writing to a string.
#include <vector>
#include <string>

namespace files
{
    class Reader
    {
    public:
        Reader(std::string fileName);

        template <typename T>
        std::vector<T> const readFile()
        {
            std::ifstream is{this->fileName};
            std::vector<T> vec;

            if (!is)
            {
                std::cerr << "These was an error IS";
                return vec;
            }

            std::string line;
            while (is)
            {
                std::getline(is, line);
                vec.push_back(line);

                if (is.eof()) // Check for end of file so that the last line doesn't get added twice.
                {
                    break;
                }
            }

            is.close();

            return vec;
        }

        void writeFile(std::vector<std::string> const &vec);

    private:
        std::string fileName;
    };
};

#endif
