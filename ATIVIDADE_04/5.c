#include <stdio.h>
#include <math.h>

double fees(float value, float tax, int month)
{
    if(month == 0)
        return value;
    else
        return (1 + tax/ 100) * fees(value, tax, month - 1);
}


int main()
{
   float value, tax;
   int month;
   printf("valor: ");
   scanf("%f",&value);
   printf("taxa e tempo: ");
   scanf("%f%d",&tax, &month);
   double result = fees(value, tax, month);
   printf("valor com juros = %.2f R$\n",result);
   printf("juros = %.2f R$\n",result - value);
}
