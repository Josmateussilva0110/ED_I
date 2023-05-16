#include <stdio.h>
#include <stdlib.h>

void print(int *array, int size);

int main()
{
    int tam, value;
    printf("tamanho do array: ");
    scanf("%d",&tam);
    int *array = malloc(tam * sizeof(int));
    int *P_array = array;
    for(int i = 0; i < tam; i++)
    {
        scanf("%d",&value);
        *P_array = value;
        P_array++;
    }
    print(array, tam);
    free(array);
}

void print(int *array, int size)
{
    int *P_array = array;
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",*P_array);
        P_array++;
    }
}