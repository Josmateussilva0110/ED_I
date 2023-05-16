#include <stdio.h>

int main()
{
    int a;
    int b;
    scanf("%d%d",&a,&b);
    printf("a = %p\n",&a);
    printf("b = %p\n",&b);
    int *P_a = &a;
    int *P_b = &b;
    if(P_a > P_b)
        printf("maior endereco = %d\n",*P_a);
    else
        printf("maior endereco = %d\n",*P_b);
}