#include <stdio.h>
#include <stdlib.h>
#include "listaestatica.h"
#include "listaestatica.c"

int main()
{
	int pos = 0, tam = 2;
	Conta *lista = criarListaContasEstatica(tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	//inserirElemento(lista, pos++, tam);
	//inserirElemento(lista, pos++, tam);
	removerElemento(lista, tam);
	int op;
	printf("digite o numero da conta que deseja buscar: ");
	scanf("%d",&op);
	int indice = buscarElemento(lista, tam, op);
	if(indice != -1)
		printf("a conta foi encontrada na posicao %d\n",indice);
	else
		printf("conta nao encontrada.\n");
	int op2;
	printf("digite o numero da conta que deseja ver o saldo: ");
	scanf("%d",&op2);
	mostrarSaldo(lista, op2, tam);
	liberarMemoria(lista);
	return 0;
}