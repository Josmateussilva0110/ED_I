#include <stdio.h>

void bigger(int x, int y, int *P_maior, int *P_menor);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    bigger(a, b, &a, &b);
    printf("maior valor = %d\nmenor valor = %d\n", a, b);
}

void bigger(int x, int y, int *P_maior, int *P_menor)
{
    if (x > y)
    {
        *P_maior = x;
        *P_menor = y;
    }
    else
    {
        *P_maior = y;
        *P_menor = x;
    }
}
