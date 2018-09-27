#include <stdio.h>

int used[26];
char prefix[26];
void rec(int num, int left, int startIndex)
{
    int i = 0;
    int j;

    for (i = 0; i < num; i++)
    {
        if (used[i] == 0)
            continue;
        
        used[i] =0;
        prefix[startIndex] = 'a' + i;
        if(left >1){
        rec(num, left -1, startIndex + 1);
        }
        if (left == 1)
        {
                printf("%s\n",prefix);
        }

        used[i]=1;

    }
}

int main(void)
{
    int a, b, c;
    int arr[26];
    int minNumber, minIndex;
    int i, j;

    int tmp;

    for (i = 0; i < 26; i++)
    {
        used[i] = 1;
    }
    scanf("%d %d", &a, &b);

    prefix[a] = '\0';
    rec(a, b, 0);
}