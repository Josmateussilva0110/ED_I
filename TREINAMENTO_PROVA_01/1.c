#include <stdio.h>

int sum_values(int k)
{
    if(k == 0)
    {
        printf("%d\n",k);
        return k;
    }
    else
    {
        printf("%d\n",k);
        return k + sum_values(k -1);
    }
}

int main()
{
    int k;
    scanf("%d",&k);
    int result = sum_values(k);
    printf("%d\n",result);
}