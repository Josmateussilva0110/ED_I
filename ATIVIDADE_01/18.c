#include <stdio.h>
#include <stdlib.h>

void calc_esfera(float R, float *area, float *volume);


int main()
{
    float value, zone, bulk;
    scanf("%f",&value);
    calc_esfera(value, &zone, &bulk);
    printf("area = %.2f\n",zone);
    printf("volume = %.2f\n",bulk);
}

void calc_esfera(float R, float *area, float *volume)
{
    float pi = 3.14159;
    *area = 4 * pi * (R * R);
    *volume = 4/3 * pi * (R * R * R);
}
