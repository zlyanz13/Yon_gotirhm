#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string x;
    getline(cin, x);

    for (int i = 0; i < x.length(); i++)
    {
        cout << x[x.length() - i - 1];
    }
}