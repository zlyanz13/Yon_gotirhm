#include <iostream>
#include <string>
using namespace std;

int T;

int main(int argc, char **argv)
{
    int test_case;
    cin >> T;
    /*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int a, b, c;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;

        string paren;
        cin >> paren;

        int size = paren.length();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (paren[i] == '(')
            {
                count++;
                if (i + 1 < size && paren[i + 1] == ')')
                {
                    answer += --count;
                    i++;
                }
                else
                {
                    answer++;
                }
            }
            else
            {
                count--;
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}