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
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            x[i] = x[i] - 'A' + 'a';
        }
        else if (x[i] >= 'a' && x[i] <= 'z')
        {
            x[i] = x[i] + 'A' - 'a';
        }
    }
    cout << x << endl;
}