#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phoneBook)
{
    bool answer = true;

    int size = phoneBook.size();
    for (int i = 0; i < size; i++)
    {
        string tmp = phoneBook[i];
        int tmpL = tmp.size();

        for (int j = 0; j < size; j++)
        {
            if (i == j || phoneBook[j].size() <= tmpL)
                continue;
            if (phoneBook[j].erase(tmpL).compare(tmp) == 0)
            {
                return false;
            }
        }
    }
    return answer;
}