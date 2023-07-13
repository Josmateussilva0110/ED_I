#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include "funcioes.c"


int main()
{
    Pessoa *P = NULL;
    //P = inserirPessoaInicio(P);
    //P = inserirPessoaInicio(P);
    //P = inserirPessoaInicio(P);
    //P = inserirPessoaFim(P);
    //P = inserirPessoaFim(P);
    //P = inserirPessoaFim(P);
    P = inserirPessoaOrdenado(P);
    P = inserirPessoaOrdenado(P);
    //P = inserirPessoaOrdenado(P);
    mostrarTodasPessoas(P);
    int opc;
    printf("id da pessoa que deseja buscar: ");
    scanf("%d",&opc);
    buscarPessoa(P, opc);
    P = removerPessoa(P);
    mostrarTodasPessoas(P);
    liberar(P);
}