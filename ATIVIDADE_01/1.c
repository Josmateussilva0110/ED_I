#include <stdio.h>

int main()
{
    int x = 10;
    float y = 12.5;
    char z = 'a';
    int *P_int = &x;
    float *P_float = &y;
    char *P_char = &z;
    printf("valores das variaves: \n");
    printf("x = %d\ny = %.2f\nz = %c\n",x,y,z);
    *P_int = 20;
    *P_float = 15.50;
    *P_char = 'b';
    printf("valores dos ponteiros: \n");
    printf("x = %d\ny = %.2f\nz = %c\n",x,y,z);
}
