#include <string>
#include <vector>

using namespace std;

int N;

vector<vector<int>> Wboard;
vector<int> com;

bool isPossible(int num, vector<vector<int>> board)
{
    int count = 0;

    int fx = 99999;
    int fy = 99999;
    int lx = -1;
    int ly = -1;

    for (int i = 0; i < com.size(); i++)
    {
        if (num == com[i])
        {
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Wboard[i][j] == num)
            {
                count++;

                if (fx > j)
                    fx = j;
                if (fy > i)
                    fy = i;

                if (lx < j)
                    lx = j;
                if (ly < i)
                    ly = i;
            }
            if (count == 4)
            {
                break;
            }
        }
        if (count == 4)
            break;
    }

    if (count != 4)
        return false;

    for (int i = fy; i < ly + 1; i++)
    {
        for (int j = fx; j < lx + 1; j++)
        {
            int k = i - 1;

            if (Wboard[i][j] == 0)
            {
                while (k >= 0)
                {
                    if (Wboard[k][j] != 0)
                    {
                        return false;
                    }
                    k--;
                }
            }
            if (Wboard[i][j] != num && Wboard[i][j] != 0)
            {
                return false;
            }
        }
    }

    count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Wboard[i][j] == num)
            {
                Wboard[i][j] = 0;
                count++;
            }
            if (count == 4)
                break;
        }
        if (count == 4)
            break;
    }
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    N = board.size();
    int count = 0;
    int number = 0;
    for (int i = 0; i < N; i++)
    {
        Wboard.push_back(board[i]);
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 0)
            {
                count++;
            }
        }
    }
    count = count / 4;

    for (int i = 0; i < count; i++)
    {
        if (isPossible(i + 1, board))
        {
            answer++;
            com.push_back(i + 1);
            i = -1;
        }
    }
    return answer;
}