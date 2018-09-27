#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> leftP;

string paren;

int main(void)
{
    cin >> paren;
    bool answer = true;
    int size = paren.length();

    for (int i = 0; i < size; i++)
    {
        if (paren[i] == '(')
        {
            leftP.push('(');
        }
        else if (paren[i] == ')')
        {
            if (leftP.empty())
            {
                answer = false;
                break;
            }
            else
            {
                leftP.pop();
            }
        }
    }
    if (!leftP.empty())
    {
        answer = false;
    }

    string rValue = answer ? "YES" : "NO";
    cout << rValue;
}
