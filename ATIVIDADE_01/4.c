#include <stdio.h>

void swap(int x, int y);

int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    printf("valor de A = %d\n",a);
    printf("valor de B = %d\n",b);
    printf("depois da troca:\n");
    swap(a, b);
}

void swap(int x, int y)
{
    int *P_x = &y;
    int *P_y = &x;
    printf("valor de A = %d\n",*P_x);
    printf("valor de B = %d\n",*P_y);
}