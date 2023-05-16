#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a;
    int *b, **c, ***d;
    printf("valor de A: ");
    scanf("%d",&a);
    b = &a;
    c = &b;
    d = &c;
    printf("dobro = %d\n",2 * *b);
    printf("triplo = %d\n",3 * **c);
    printf("quadruplo = %d\n",4 * ***d);
}
