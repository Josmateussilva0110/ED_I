#include <stdio.h>

int print(int k)
{
   if(k > 0)
    {
        printf("%d\n",k);
        return k += print(k - 1);
    }
    else
    {
       printf("%d\n",k);
       return k;
    }
}

int main()
{
    int value;
    printf("valor: ");
    scanf("%d",&value);
    int result = print(value);
    printf("soma = %d\n",result);
}