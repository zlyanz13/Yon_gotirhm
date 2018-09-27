#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main(void)
{
    string x;
    getline(cin, x);
    vector<string> y = split(x, ' ');

    for (int i = 0; i < y.size(); i++)
    {
        cout << y[i];
    }
}