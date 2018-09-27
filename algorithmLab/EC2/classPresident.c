#include <stdio.h>

int arr[1000][5];

int main(void)
{
    int studentNum;
    int i, j, k;

    scanf("%d", &studentNum);

    for (i = 0; i < studentNum; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int max = -1;
    int maxID = -1;
    int count = 0;

    int studentID;
    for (studentID = 0; studentID < studentNum; studentID++)
    {
        count = 0;

        for (i = 0; i < studentNum; i++)
        {
            if (i == studentID)
                continue;

            for (j = 0; j < 5; j++)
            {
                if (arr[i][j] == arr[studentID][j])
                {
                    count++;
                    break;
                }
            }            
        }

        if(count>max){
            max = count;
            maxID = studentID+1;
        }
    }
    printf("%d", maxID);
}