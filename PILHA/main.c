#include <stdio.h>
#include <stdlib.h>
#include "func.c"


int main()
{
    Pilha *p = criar_pilha();;
    pilha_push(p, 5);
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_pop(p);
    pilha_pop(p);
    imprimir(p);
}