#include "proto.h"
#include <stdlib.h>
#include <stdio.h>

struct pessoa
{
    int idade, id;
    float altura;
    char nome[100];
    Pessoa *prox;
    //struct pessoa *prox;
};

Pessoa *inserirPessoaInicio(Pessoa *lista)
{
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    // cabeca da lista, aponta para a antiga cabeca
    new->prox = lista;
    // aponta para a nova pessoa
    lista = new;
    return lista;
}

Pessoa *inserirPessoaFim(Pessoa *lista)
{
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    new->prox = NULL;
    if(lista == NULL)
    {
        lista = new;
        return lista;
    }
    Pessoa *atual = lista;
    // procurar a ultima posicao
    while(atual->prox != NULL)
    {
        atual = atual->prox;
    }
    // adicionar na ultima posicao
    atual->prox = new;
    return lista;
}

Pessoa *inserirPessoaOrdenado(Pessoa *lista)
{
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    new->prox = NULL;
    if(lista == NULL || new->id < lista->id)
    {
        // cabeca da lista, na interacao 1ª é a posicao 0
        new->prox = lista;
        // nova posicao
        lista = new;
    }
    else
    {
        Pessoa *anterior = NULL;
        Pessoa *atual = lista;
        while(atual != NULL && new->id >= atual->id)
        {
            anterior = atual;
            atual = atual->prox;
        }
        new->prox = atual;
        anterior->prox = new;
    }
    return lista;
}

void mostrarPessoa(Pessoa p)
{
    printf("idade = %d\n", p.idade);
    printf("id = %d\n", p.id);
    printf("altura = %.2f\n", p.altura);
    printf("nome = %s\n", p.nome);
}

void mostrarTodasPessoas(Pessoa *lista)
{
    if (lista == NULL)
    {
        printf("lista vazia.\n");
        return;
    }
    if(lista->prox != NULL)
        mostrarTodasPessoas(lista->prox);
    printf("idade = %d\n", lista->idade);
    printf("id = %d\n", lista->id);
    printf("altura = %.2f\n", lista->altura);
    printf("nome = %s\n", lista->nome);
}

void buscarPessoa(Pessoa *lista, int op)
{
    int valid = -1;
    if(lista == NULL)
    {
        printf("lista vazia.\n");
        return;
    }
    Pessoa *aux = lista;
    while(aux != NULL)
    {
        if(op == aux->id)
        {
            valid = 1;
            break;
        }
        aux = aux->prox;
    }
    if(valid)
        mostrarPessoa(*aux);
    else
        printf("pessoa nao encontrada.\n");
}

void liberar(Pessoa *lista)
{
    Pessoa *atual = lista;
    Pessoa *proximo;
    while(atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

Pessoa *removerPessoa(Pessoa *lista)
{
    if (lista == NULL)
    {
        printf("lista vazia.\n");
    }

    int id;
    printf("Digite o id da pessoa a ser removida: ");
    scanf("%d", &id);

    Pessoa *atual = lista;
    Pessoa *anterior = NULL;

    // Caso seja a primeira pessoa
    if (atual != NULL && atual->id == id)
    {
        lista = atual->prox;
        free(atual);
        printf("Pessoa removida com sucesso.\n");
        return lista;
    }

    // Percorrer a lista para encontrar a proxima pessoa
    while (atual != NULL && atual->id != id)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Pessoa nao encontrada.\n");
    }

    // Atualizar o ponteiro para a proxima posicao
    if (anterior != NULL) {
        anterior->prox = atual->prox;
    }
    free(atual);
    printf("Pessoa removida com sucesso.\n");
    return lista;
}