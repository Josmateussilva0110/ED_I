#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    float array[10];
    for(int i = 0; i < 10; i++)
    {
        array[i] = rand() % 10;
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%p\n",&array[i]);
    }
}
