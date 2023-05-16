#include <stdio.h>
#include <stdlib.h>

void min_max(int *array, int *min, int *max, int tam);

int main()
{
    int size, i, min, max;
    printf("tamanho do array: ");
    scanf("%d",&size);
    int *array = malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
    {
        scanf("%d", (array + i));
    }
    min_max(array, &min, &max, size);
    printf("valor minimo do array = %d\n",min);
    printf("valor maximo do array = %d\n",max);
    free(array);
}

void min_max(int *array, int *min, int *max, int tam)
{
    int *Ptr = array;
    *min = array[0];
    *max = array[0];
    for(int i = 0; i < tam; i++)
    {
        if(*Ptr > *max)
            *max = *Ptr;
        if(*Ptr < *min)
            *min = *Ptr;
        Ptr++; 
    }
}