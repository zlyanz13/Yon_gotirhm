#include <string>
#include <vector>

using namespace std;

double *rate;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    int usernum = stages.size();

    rate = new double[N + 1];

    for (int i = 1; i < N + 1; i++)
    {
        int fail = 0;
        int all = 0;
        for (int j = 0; j < usernum; j++)
        {
            if (stages[j] >= i)
            {
                all++;
                if (stages[j] == i)
                {
                    fail++;
                }
            }
        }
        if (all != 0)
        {
            rate[i] = (double)fail / (double)all;
        }
        else
        {
            rate[i] = 0;
        }
    }

    int count = 0;

    while (count < N)
    {
        int maxnum = -1;
        double max = -1;
        for (int i = 1; i < N + 1; i++)
        {
            if (rate[i] > max)
            {
                max = rate[i];
                maxnum = i;
            }
        }
        rate[maxnum] = -1;
        answer.push_back(maxnum);

        count++;
    }

    return answer;
}