#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("tamanho do array: ");
    scanf("%d",&size);
    int array[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    int *P_array = array;
    printf("valores originais:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",array[i]);
    }
    printf("valores modificados:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",*P_array+1);
        P_array++;
    }
}