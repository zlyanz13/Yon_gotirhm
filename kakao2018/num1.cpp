#include <string>
#include <vector>
#include <iostream>

using namespace std;

string come = "님이 들어왔습니다.";
string out = "님이 나갔습니다.";

struct user
{
    string uid;
    string username;
};

vector<struct user *> userlist;

int checkUid(string uid)
{
    int nn = userlist.size();
    for (int i = 0; i < nn; i++)
    {
        if (userlist[i]->uid == uid)
        {
            return i;
        }
    }
    return -1;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    string tmpid;
    string tmpname;

    struct user *newUser;

    int N = record.size();

    for (int i = 0; i < N; i++)
    {
        if (record[i][0] == 'L')
        {
            continue;
        }
        string exc = record[i];
        tmpid = exc.substr(exc.find(' ') + 1, exc.length() - exc.find(' '));
        tmpname = tmpid;
        tmpid = tmpid.substr(0, tmpid.find(' '));
        tmpname = tmpname.substr(tmpname.find(' ') + 1, tmpname.length() - tmpname.find(' '));
        int index = checkUid(tmpid);
        if (record[i].at(0) == 'E')
        {
            if (index == -1)
            {
                newUser = new struct user;
                newUser->uid = tmpid;
                newUser->username = tmpname;
                userlist.push_back(newUser);
            }
            else
            {
                userlist[index]->username = tmpname;
            }
        }

        else if (record[i].at(0) == 'C')
        {

            if (index != -1)
            {
                userlist[index]->username = tmpname;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (record[i][0] == 'C')
        {
            continue;
        }
        string exc = record[i];
        tmpid = exc.substr(exc.find(' ') + 1, exc.length() - exc.find(' '));
        tmpid = tmpid.substr(0, tmpid.find(' '));

        int index = checkUid(tmpid);

        if (record[i].at(0) == 'E')
        {
            if (index != -1)
            {
                answer.push_back(userlist[index]->username + come);
            }
        }

        else if (record[i].at(0) == 'L')
        {
            if (index != -1)
            {
                answer.push_back(userlist[index]->username + out);
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<string> record;

    record.push_back("Enter uid1234 prodo");
    record.push_back("Enter uid4567 jayz");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 open");
    record.push_back("Change uid4567 prodo");
    record.push_back("Enter uid12334 Kool");
    record.push_back("Change uid12334 Kosol");
    record.push_back("Leave uid12334");

    vector<string> answer = solution(record);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}