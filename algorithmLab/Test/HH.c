#include <stdio.h>

int main(void)
{
    int a, b, c;
    int arr[1000];
    int minNumber, minIndex;
    int i, j;
    int tmp;

    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < a - 1; i++)
    {
        minIndex = i;
        minNumber = arr[i];

        for (j = i + 1; j < a; j++)
        {
            if (arr[j] < minNumber)
            {
                minNumber = arr[j];
                minIndex = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }

    for (i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}