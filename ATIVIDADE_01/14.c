#include <stdio.h>
#include <stdlib.h>

void occupy(int* array, int value, int size);

int main()
{
    int value, tam;
    printf("tamanho do array: ");
    scanf("%d", &tam);
    int *array = malloc(tam * sizeof(int));
    printf("valor que deseja preencher: ");
    scanf("%d", &value);
    occupy(array, value, tam);
    free(array);
}

void occupy(int *array, int value, int size) 
{
    int *Ptr = array;
    for(int i = 0; i < size; i++) 
    {
        *Ptr = value;
        Ptr++;
    }
    Ptr = array;
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", *Ptr);
        Ptr++;
    }
}