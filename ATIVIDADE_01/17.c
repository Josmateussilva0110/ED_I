#include <stdio.h>
#include <stdlib.h>

void frac(float num, int* inteiro, float* frac);


int main()
{
    int inteiro;
    float value, fraci;
    scanf("%f",&value);
    frac(value, &inteiro, &fraci);
    printf("parte inteiro = %d\n",inteiro);
    printf("parte fracionaria = %.2f\n",fraci);
}

void frac(float num, int *inteiro, float *frac)
{
    *inteiro = (int) num;
    *frac = num - *inteiro;
}