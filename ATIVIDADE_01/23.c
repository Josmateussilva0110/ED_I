#include <stdio.h>
#include <stdlib.h>

int upper(int *array, int tam);

int main()
{
    int size, i, k, maior;
    printf("tamanho do array: ");
    scanf("%d",&size);
    int *array = malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
    {
        scanf("%d", (array + i));
    }
    int *P_array = array;
    printf("valor de k: ");
    scanf("%d",&k);
    for(i = 0; i < size; i++)
    {
        printf("%d\t",*P_array);
        if(i == k - 1)
            printf("\n");
        P_array++;
    }
    printf("\n");
    maior = upper(array, size);
    printf("maior elemento = %d\n",maior);
    free(array);
}

int upper(int *array, int tam)
{
    int maior = array[0];
    int *Ptr = array;
    for(int i = 0; i < tam; i++)
    {
        if(*Ptr > maior)
            maior = *Ptr;
        Ptr++;
    }
    return maior;
}