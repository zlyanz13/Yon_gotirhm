#include <string>
#include <vector>

using namespace std;

vector<int> heap;

void dMax()
{
    int n = heap.size();
    int max = -10000000;
    int maxIndex = -1;

    if (n == 1)
    {
        heap.clear();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (heap[i] > max)
        {
            max = heap[i];
            maxIndex = i;
        }
    }
    heap.erase(heap.begin() + maxIndex);
}

void dMin()
{
    int n = heap.size();
    int min = 10000000;
    int minIndex = -1;

    if (n == 1)
    {
        heap.clear();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (heap[i] < min)
        {
            min = heap[i];
            minIndex = i;
        }
    }
    heap.erase(heap.begin() + minIndex);
}

vector<int> solution(vector<string> arguments)
{
    vector<int> answer;
    int N = arguments.size();

    string input;

    for (int i = 0; i < N; i++)
    {
        input = arguments[i];
        if (input.front() == 'I')
        {
            heap.push_back(stoi(input.erase(0, 2)));
        }
        else if (input.front() == 'D')
        {
            if (heap.size() == 0)
            {
                continue;
            }
            if (input[2] == '1')
            {
                dMax();
            }
            else if (input[2] == '-')
            {
                dMin();
            }
        }
    }

    if (heap.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        int MAX = -10000000;
        int MIN = 10000000;
        int a = heap.size();
        for (int i = 0; i < a; i++)
        {
            if (heap[i] > MAX)
            {
                MAX = heap[i];
            }
            if (heap[i] < MIN)
            {
                MIN = heap[i];
            }
        }

        answer.push_back(MAX);
        answer.push_back(MIN);
    }

    return answer;
}