#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value, tam = 0, sum = 0, upper, lower, i = 0;
    int *array = NULL;
    float media;
    while(1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        tam++;
        array = (int*) realloc(array, tam * sizeof(int));
        array[tam -1] = value;
        sum += value;
        upper = array[0];
        lower = array[0];
        if(value > upper)
            upper = value;
        if(value < lower)
            lower = value;
    }
    media = (float) sum / tam;
    printf("o valor do somatorio = %d\n",sum);
    printf("o valor da media = %.2f\n",media);
    printf("maior valor = %d\n",upper);
    printf("menor valor = %d\n",lower);
    printf("valores do array:\n");
    int *P_array = array;
    while(i < tam)
    {
        printf("%d\n",*P_array);
        P_array++;
        i++;
    }
    free(array);
}