#include "Utils.h"

vector<string> split(const string& str, char delimiter)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos)
    {
        //string::npos valoare specială este utilizată pentru a indica o poziție invalidă sau inexistența unei subșiruri în cadrul unui obiect std::string.

        std::string substring = str.substr(start, end - start);
        result.push_back(substring);
        start = end + 1;
        end = str.find(delimiter, start);
    }


    string substring = str.substr(start);
    result.push_back(substring);

    return result;
}
