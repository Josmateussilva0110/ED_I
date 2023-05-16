#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N);

int main()
{
    int size, result;
    float value;
    printf("tamanho do array: ");
    scanf("%d",&size);
    float *array = malloc(size * sizeof(int));
    float *P_array = array;
    for(int i = 0; i < size; i++)
    {
        scanf("%f",&value);
        *P_array = value;
        P_array++;
    }
    result = negativos(array, size);
    printf("numeros negativos = %d\n",result);
    free(array);
}

int negativos(float *vet, int N)
{
    float *P_vet = vet;
    int cont = 0;
    for(int i = 0; i < N; i++)
    {
        if(*P_vet < 0.0)
            cont++;
        P_vet++;
    }
    return cont;
}