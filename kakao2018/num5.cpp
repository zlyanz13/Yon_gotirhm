#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;

struct cord
{
    bool done = false;
    int num;
    int x;
    int y;
    struct cord *left = NULL;
    struct cord *right = NULL;
};

vector<struct cord *> tree;
queue<struct cord *> drawq;

vector<int> preV;
vector<int> postV;

struct cord *root;
struct cord *first;

void drawedge(struct cord *tmpnode)
{
    if (tmpnode == root)
    {
        return;
    }
    if(tmpnode->done){
        return;
    }
    struct cord *tmpN = NULL;

    int nx = tmpnode->x;
    int ny = tmpnode->y;

    int maxY = 100001;
    int min = 100001;

    for (int i = 0; i < N; i++)
    {
        int ty = tree[i]->y;
        if (ty - ny > 0 && (ty - ny < maxY))
        {
            maxY = ty - ny;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int tx = tree[i]->x;
        int ty = tree[i]->y;
        if ((ty - ny) == maxY)
        {

            int sub;
            if (tx > nx)
            {
                sub = tx - nx;
            }
            else if (tx < nx)
            {
                sub = nx - tx;
            }
            if (sub < min)
            {
                min = sub;
                tmpN = tree[i];
            }
        }
    }
    if (tmpN != NULL)
    {
        tmpnode->done = true;
        if (tmpN->x > nx)
            tmpN->left = tmpnode;

        else if (tmpN->x < nx)
            tmpN->right = tmpnode;
    }

    int flag = 1;
    for (int i = 0; i < N; i++)
    {
        int ty = tree[i]->y;
        if (ty == ny)
        {
            if (!tree[i]->done)
            {
                drawq.push(tree[i]);
                flag = 0;
            }
        }
    }

    min = 999999;
    int minnum = -1;
    if (flag)
    {
        for (int i = 0; i < N; i++)
        {
            int ty = tree[i]->y;
            if (ty > ny && ty < min)
            {
                min = ty;
                minnum = i;
            }
        }
        drawq.push(tree[minnum]);
    }
}

void preO(struct cord *node)
{
    if (node == NULL)
    {
        return;
    }
    preV.push_back(node->num);

    if (node->left != NULL)
        preO(node->left);
    if (node->right != NULL)
        preO(node->right);
}

void postO(struct cord *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
        postO(node->left);
    if (node->right != NULL)
        postO(node->right);
    postV.push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    N = nodeinfo.size();

    int max = -1;
    int maxNum = -1;
    int min = 1000000;
    int minnum = 1000000;

    struct cord *newNode;
    for (int i = 0; i < N; i++)
    {
        newNode = new struct cord;
        newNode->num = i + 1;
        newNode->x = nodeinfo[i][0];
        newNode->y = nodeinfo[i][1];

        if (newNode->y > max)
        {
            max = newNode->y;
            maxNum = i;
        }
        if (newNode->y < min)
        {
            min = newNode->y;
            minnum = i;
        }

        tree.push_back(newNode);
    }
    root = tree[maxNum];
    drawq.push(tree[minnum]);
    while (!drawq.empty())
    {
        drawedge(drawq.front());
        drawq.pop();
    }

    preO(root);
    postO(root);

    answer.push_back(preV);
    answer.push_back(postV);
    return answer;
}