#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("a = %p\n",&a);
    printf("b = %p\n",&b);
    if(a > b)
        printf("maior endereco = %p\n",&a);
    else
        printf("maior endereco = %p\n",&b);
}