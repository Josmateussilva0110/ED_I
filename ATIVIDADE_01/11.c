#include <stdio.h>

int main()
{
    int array[5];
    for(int i = 0; i < 5; i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        if(array[i] % 2 == 0)
            printf("%p\n",&array[i]);
    }
}
