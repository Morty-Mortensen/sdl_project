#include "Reader.h"

using namespace std;

namespace files
{
    Reader::Reader(string fileName) : fileName(fileName) {}

    template <typename T>
    vector<T> const Reader::readFile()
    {
        ifstream is{this->fileName};
        vector<T> vec;

        if (!is)
        {
            cerr << "These was an error IS";
            return vec;
        }

        string line;
        while (is)
        {
            getline(is, line);
            vec.push_back(line);

            if (is.eof()) // Check for end of file so that the last line doesn't get added twice.
            {
                break;
            }
        }

        is.close();

        return vec;
    }

    void Reader::writeFile(vector<string> const &vec)
    {
        ofstream os{this->fileName};

        if (!os)
        {
            cerr << "These was an error OS";
            return;
        }

        for (const string &line : vec)
        {
            os << line << '\n';
        }

        os.close();
    }

    template vector<string> const Reader::readFile<string>();
}