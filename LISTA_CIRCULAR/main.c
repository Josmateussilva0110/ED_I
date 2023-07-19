#include <stdio.h>
#include <stdlib.h>
#include "circular.c"


int main()
{
    Lista lista;
    criar(&lista);
    inserir_inicio(&lista);
    inserir_inicio(&lista);
    //inserir_fim(&lista);
    //inserir_fim(&lista);
    //inserir_ordenado(&lista);
    //inserir_ordenado(&lista);
    imprimir(lista);
    int op;
    printf("pessoa que deseja buscar: ");
    scanf("%d",&op);
    No *aux = buscar(&lista, op);
    exibir_um(aux);
    int op2;
    printf("pessoa que deseja buscar: ");
    scanf("%d",&op2);
    No *aux2 = remover(&lista, op2);
    free(aux2);
    imprimir(lista);
}