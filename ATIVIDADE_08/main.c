#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"
#include "prototipo.h"

int main()
{
    Matriz *mat;
    mat = cria(3, 3);
    atribui(mat, 1, 2, 3);
    atribui(mat, 0, 0, 5);
    atribui(mat, 1, 1, 3);
    float a = acessa(mat, 0, 0);
    print(mat);
    printf("%.2f\n",a);
    int tam = linhas(mat);
    int tam2 = colunas(mat);
    printf("quantidade de linhas da matriz = %d\n",tam);
    printf("quantidade de colunas da matriz = %d\n",tam2);
    libera(mat);
}