#include "prototipos.h"
#include "funcoes.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Pessoa *lista = NULL;
    //inserirPessoaInicio(&lista); 
    //inserirPessoaFim(&lista);
    inserir(&lista);
    int ans = contarPessoasNaLista(lista); 
    printf("quantidade de pessoas = %d\n",ans);
    mostrarTodasPessoas(lista);
    buscarPessoa(lista);
    removerPessoa(lista);
    liberarMemoria(lista);
}