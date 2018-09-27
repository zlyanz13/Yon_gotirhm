#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string x;
    getline(cin, x);

    string y = "";
    int size = x.length();
    char what = '\0';
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (what == x[i])
        {
            count++;
        }
        else
        {

            if (count > 1)
            {
                string a = "";
                a += '0' + (char)(count % 10);
                count /= 10;
                while (count != 0)
                {
                    a.insert(0, 1, '0' + (char)(count % 10));
                    count /= 10;
                }
                y += a;
                y += what;
            }
            else if (count == 1)
            {
                y += what;
            }
            what = x[i];
            count = 1;
        }
    }
    if (count > 1)
    {
        string a = "";
        a += '0' + (char)(count % 10);
        count /= 10;
        while (count != 0)
        {
            a.insert(0, 1, '0' + (char)(count % 10));
            count /= 10;
        }
        y += a;
        y += what;
    }
    else if (count == 1)
    {
        y += what;
    }

    cout << y << endl;
}