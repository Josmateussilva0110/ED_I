#include <stdio.h>

int sum_values(int a, int b)
{
    int lower, upper;
    if(a > b)
    {
        upper = a;
        lower = b;
    }
    else
    {
        upper = b;
        lower = a;
    }
    if(lower + 1 >= upper)
        return 0;
    else
        return (lower + 1) + sum_values(lower + 1, upper);
}

int main()
{
    int value1, value2;
    printf("valor 1 e 2: ");
    scanf("%d%d", &value1, &value2);
    int result = sum_values(value1, value2);
    printf("soma = %d\n", result);
    return 0;
}
