#include <stdio.h>
#include <stdlib.h>

int search(int *array, int value, int size)
{
    if(*array == value)
        return 1;
    if(size > 0)
        return search(array + 1, value, size - 1);
    return 0; 
}

int main()
{
    int size;
    scanf("%d",&size);
    int *array = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        scanf("%d",(array + i));
    }
    int value, valid;
    int *P_array = array;
    printf("valor q deseja: ");
    scanf("%d",&value);
    valid = search(P_array, value, size);
    if(valid)
        printf("valor %d encontrado!\n",value);
    else
        printf("valor %d nao encontrado!\n",value);
    free(array);
}
