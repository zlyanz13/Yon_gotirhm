#include <stdio.h>

int main(void)
{
    int n;
    int x, y;
    int i, j, count;

    int gcd, lcm;

    scanf("%d %d", &x, &y);

    i = 2;
    while(1){
        if((i%x ==0)&&(i%y ==0)){
            gcd = i;
            break;
        }
        i++;
    }

    j = x;

    while(1){
        if((x%j ==0)&&(y%j)==0){
            lcm = j;
            break;
        }
        j--;
    }

    printf("%d\n%d", lcm, gcd);
}