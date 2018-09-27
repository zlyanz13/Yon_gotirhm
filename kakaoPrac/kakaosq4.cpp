#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    int N = prices.size();

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (prices[i] > prices[j])
            {
                answer.push_back(j - i);
                break;
            }
            if (j == N - 1)
            {
                answer.push_back(j - i);
            }
        }
    }
    answer.push_back(0);

    return answer;
}