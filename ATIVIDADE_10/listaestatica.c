#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaestatica.h"


struct conta
{
	float saldo;
	int num_conta;
	char nome[100];
	
};
Conta *criarListaContasEstatica(int tam){
	Conta *listaContas = (Conta*) calloc(sizeof(Conta), tam);
	return listaContas;
}
void inserirElemento(Conta *lista, int p, int t){
	srand(time(NULL));
	if (p < t)
	{
		scanf("%f", &lista[p].saldo);
		scanf("%s", lista[p].nome);
		lista[p].num_conta = rand() % 100 + 10;
	}
}

void mostrarElemento(Conta elemento){
	printf("\nSaldo: %.2f\nNome: %s\nNumero da Conta: %d\n", elemento.saldo, elemento.nome, elemento.num_conta);
}
void mostrarTodosElementos(Conta *lista, int t){
	for (int i = 0; i < t; ++i)
	{
		mostrarElemento(lista[i]);
	}
}


void liberarMemoria(Conta *listaContas)
{
	free(listaContas);
}


void removerElemento(Conta *lista, int t)
{
	int op;
	//int *P_t = &t;
	mostrarTodosElementos(lista, t);
	printf("insira o numero da conta que deseja remover: ");
	scanf("%d",&op);
	int indice = -1;
	for(int i = 0; i < t; i++)
	{
		if(op == lista[i].num_conta)
		{
			indice = i;
			break;
		}
	}

	if(indice == -1)
	{
		printf("pessoa nao encontrada.\n");
	}
	else
	{
		for(int i = indice; i < (t -1); i++)
		{
			lista[i] = lista[i + 1];
		}
		(t)--;
		lista = realloc(lista, (t) * sizeof(Conta));
		printf("pessoa removida com sucesso.\n");
	}	
	mostrarTodosElementos(lista, t);
}


int buscarElemento(Conta *lista, int tam, int num_conta)
{
	int indice = -1;
	for(int i = 0; i < tam; i++)
	{
		if(lista[i].num_conta == num_conta)
		{
			indice = i;
			break;
		}
	}
	if(indice != -1)
	{
		mostrarElemento(lista[indice]);
		return indice;
	}
	else
	{
		printf("numero nao encontrado.\n");
		return indice;
	}
}

void mostrarSaldo(Conta *lista, int num_conta, int tamanho)
{
	int valid = 0;
	for(int i = 0; i < tamanho; i++)
	{
		if(lista[i].num_conta == num_conta)
		{
			printf("saldo da conta %d é:\n",num_conta);
			printf("%.2f\n",lista[i].saldo);
			valid = 1;
			break;
		}
	}
	if(!valid)
		printf("conta nao encontrada\n");
}
