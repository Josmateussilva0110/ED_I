#include <stdio.h>

int sun(int x, int y);

int main()
{
    int a, b, result;
    scanf("%d%d", &a, &b);
    result = sun(a, b);
    printf("%d\n",result);
}

int sun(int x, int y)
{
    int dobro_x = x * x;
    int dobro_y = y * y;
    int *P_dobro_x = &dobro_x; 
    int *P_dobro_y = &dobro_y;
    x = *P_dobro_x;
    y = *P_dobro_y;
    int sun = x + y;
    return sun;
}