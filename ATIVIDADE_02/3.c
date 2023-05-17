#include <stdio.h>
#include <stdlib.h>

int *obtem_produtos_zerados(int *codigo, int *estoque, int num_produtos, int *zerados);

int main()
{
    int size, i, j = 0;
    int zerados;
    printf("quantidade de produtos: ");
    scanf("%d",&size);
    int *codigo = malloc(size * sizeof(int));
    int *estoque = malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
    {
        printf("digite o codigo %d: \n",i);
        scanf("%d",(codigo + i));
    }
    for(i = 0; i < size; i++)
    {
        printf("digite a quantidade %d: \n",i);
        scanf("%d",(estoque + i));
    }
    int *result = obtem_produtos_zerados(codigo, estoque, size, &zerados);
    int *P_result = result;
    printf("codigos dos produtos com estoque zerados:\n");
    while(j < zerados)
    {
        printf("%d\n",*P_result);
        P_result++;
        j++;
    }
    free(result);
    free(codigo);
    free(estoque);
}

int *obtem_produtos_zerados(int *codigo, int *estoque, int num_produtos, int *zerados)
{
    int *produtos_zerados = NULL;
    *zerados = 0;
    int aux = 0;
    for(int i = 0; i < num_produtos; i++)
    {
        if(estoque[i] == 0)
            (*zerados)++;
    }
    produtos_zerados = (int*) malloc((*zerados) * sizeof(int));
    for(int i = 0; i < num_produtos; i++)
    {
        if(estoque[i] == 0)
        {
            produtos_zerados[aux] = codigo[i];
            aux++;
        }
    }
    return produtos_zerados;
}