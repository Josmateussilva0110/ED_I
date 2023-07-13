#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include "func.c"


int main()
{
    Pessoa *p = NULL;
    //p = inserirPessoaInicio(p);
    //p = inserirPessoaInicio(p);
    //p = inserirPessoaFim(p);
    //p = inserirPessoaFim(p);
    p = inserirPessoaOrdenado(p);
    p = inserirPessoaOrdenado(p);
    mostrarTodasPessoas(p);
    int op;
    printf("id da pessoa: ");
    scanf("%d",&op);
    buscarPessoa(p, op);
    int op2;
    printf("id da pessoa para remover: ");
    scanf("%d",&op2);
    p = removerPessoa(p, op2);
    mostrarTodasPessoas(p);
    liberar(p);
}