#include <stdio.h>
#include <stdlib.h>
#include "func.c"


int main()
{
    Fila *p = criar_fila();
    fila_push(p, 5);
    fila_push(p, 10);
    fila_push(p, 20);
    imprimir(p);
    fila_pop(p);
    fila_pop(p);
    imprimir(p);
}