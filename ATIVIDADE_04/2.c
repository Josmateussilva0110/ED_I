#include <stdio.h>

void print(int k)
{
    if(k > 0)
    {
        printf("%d\n",k);
        print(k - 1);
    }
    else
    {
        printf("%d\n",k);
    }

}

int main()
{
    int value;
    printf("valor: ");
    scanf("%d",&value);
    print(value);
}