#include <stdio.h>

int expo(int b, int p)
{
    if(p == 0)
        return 1;
    else
        return b *= expo(b, p -1);
}

int main()
{
    int a, b;
    printf("base: ");
    scanf("%d",&a);
    printf("expoente: ");
    scanf("%d",&b);
    int result = expo(a, b);
    printf("%d\n",result);
}