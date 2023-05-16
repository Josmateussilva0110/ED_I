#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frequency(int *array, int size, int *upper, int *occuorrence);

int main()
{
    int tam, value, upper, occurrence;
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
    frequency(array, tam, &upper, &occurrence);
    printf("maior valor = %d\n",upper);
    printf("ocorrencias = %d\n",occurrence);
    free(array);
}

void frequency(int *array, int size, int *upper, int *occurrence)
{
    int *P_array = array, cont = 0;
    *upper = array[0];
    for(int i = 0; i < size; i++)
    {
        if(*P_array > *upper)
            *upper = *P_array;
        P_array++;
    }
    P_array = array;
    for(int i = 0; i < size; i++)
    {
        if(*P_array == *upper)
            cont++;
        P_array++;
    }
    *occurrence = cont;
}