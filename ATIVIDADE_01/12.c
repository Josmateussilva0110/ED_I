#include <stdio.h>

int ordenar(int *a, int *b, int *c) 
{
    int temp;
    if (*a > *b) 
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) 
    {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) 
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a == *b && *b == *c) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int result = ordenar(&a, &b, &c);
    printf("Valores ordenados: %d %d %d\n", a, b, c);
    printf("%d\n",result);
}
