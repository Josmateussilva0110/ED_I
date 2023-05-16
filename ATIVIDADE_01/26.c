#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float A,float B,float C,float * X1,float * X2);
float delta(float A, float B, float C);


int main()
{
    float a, b, c, x1, x2;
    int result;
    printf("valor de A, b, c: ");
    scanf("%f%f%f",&a,&b,&c);
    result = raizes(a,b,c,&x1,&x2);
    printf("quantidade de raizer = %d\n",result);
    printf("X1 = %.5f\n",x1);
    printf("X2 = %.5f\n",x2);
}

int raizes(float A,float B,float C,float *X1,float *X2)
{
    float del;
    del = delta(A, B, C);
    if(del < 0 || A == 0)
    {
        printf("impossivel calcular\n");
        return 0;
    }
    if(del == 0)
        return 1;
    if(del > 0 || A != 0)
    {
        *X1 = ((-1*B) + sqrt(del)) / (2 * A);
        *X2 = ((-1*B) - sqrt(del)) / (2 * A);
        return 2;
    }
}

float delta(float A, float B, float C)
{
    float del;
    del = (B * B) -4 * A * C;
    return del;
}