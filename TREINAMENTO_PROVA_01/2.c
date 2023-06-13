#include <stdio.h>

int sum(int a, int b)
{
    int upper, lower;
    if(a > b)
    {
        upper = a;
        lower = b;
    }
    else
    {
        upper = b;
        lower = a;
    }
    if(upper == lower)
        return upper;
    else
        return upper + sum(lower, upper -1);
}

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    int result = sum(a, b);
    printf("%d\n",result);
}