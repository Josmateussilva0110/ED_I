#include <stdio.h>

void sun(int *x, int y);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("valor de A = %d\nvalor de B = %d\n",a,b);
    sun(&a, b);
    printf("valor de A = %d\n",a);
    printf("valor de B = %d\n",b);
}

void sun(int *x, int y)
{
    *x = *x + y;
}