#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int *array1, int *array2, int size1, int size2);

int main()
{
    int tam1, tam2, result;
    printf("tamanho do array 1 e 2: ");
    scanf("%d%d",&tam1,&tam2);

    int *array1 = malloc(tam1 * sizeof(int));
    int *array2 = malloc(tam2 * sizeof(int));

    printf("valores do array 1:\n");
    for(int i = 0; i < tam1; i++)
    {
        scanf("%d", array1 + i);
    }
    printf("valores do array 2:\n");
    for(int i = 0; i < tam2; i++)
    {
        scanf("%d", array2 + i);
    }
    result = sum(array1, array2, tam1, tam2);
    printf("\n");
    printf("%d\n",result);
    free(array1);
    free(array2);
}

int sum(int *array1, int *array2, int size1, int size2)
{
    int *array3 = malloc(size1 * sizeof(int));
    if(size1 != size2)
        return 0;
    for(int i = 0; i < size1; i++)
    {
        *(array3 + i) = *(array1 + i) + *(array2 + i);
    }
    int *P_array3 = array3;
    printf("soma dos arrays:\n");
    for(int i = 0; i < size1; i++)
    {
        printf("%d\n",*P_array3);
        P_array3++;
    }
    free(array3);
    return 1;
}