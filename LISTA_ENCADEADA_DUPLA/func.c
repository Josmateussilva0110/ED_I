#include "proto.h"
#include <stdlib.h>
#include <stdio.h>

struct pessoa
{
    int idade, id;
    float altura;
    char nome[100];
    Pessoa *prox;
    Pessoa *ant;
    //struct pessoa *prox;
};


Pessoa *inserirPessoaInicio(Pessoa *lista)
{
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    // aponta para a pessoa da frente, antiga cabeca
    new->prox = lista;
    new->ant = NULL;
    if(lista)
        // aponta para a nova pessoa, a cabeca
        lista->ant = new;
    // recebe a nova pessoa 
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
        new->ant = NULL;
        return lista;
    }
    else
    {
        Pessoa *aux = lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        //recebe a pessoa na ultima posicao
        aux->prox = new;
        // recebe a antiga cabeca
        new->ant = aux;
        return lista;
    }
}

Pessoa *inserirPessoaOrdenado(Pessoa *lista)
{
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    
    if(lista == NULL)
    {
        new->prox = NULL;
        new->ant = NULL;
        lista = new;
    }

    else if(new->idade < lista->idade)
    {
        new->prox = lista;
        lista->ant = new;
        lista = new;
    }
    else
    {
        Pessoa *aux = lista;
        while(aux->prox != NULL && new->idade > aux->prox->idade)
            aux = aux->prox;
        new->prox = aux->prox;
        if(aux->prox)
            aux->prox->ant = new;
        new->ant = aux;
        aux->prox = new;
    }
}

void mostrarTodasPessoas(Pessoa *lista)
{
    Pessoa *aux = lista;
    printf("DADOS:\n");
    while(aux != NULL)
    {
        printf("idade = %d\n", aux->idade);
        printf("id = %d\n", aux->id);
        printf("altura = %.2f\n", aux->altura);
        printf("nome = %s\n", aux->nome);
        aux = aux->prox;
    }
}

void mostrarPessoa(Pessoa p)
{
    printf("idade = %d\n", p.idade);
    printf("id = %d\n", p.id);
    printf("altura = %.2f\n", p.altura);
    printf("nome = %s\n", p.nome);
}

void buscarPessoa(Pessoa *lista, int op)
{
    Pessoa *aux = lista;
    while(aux != NULL && aux->id != op)
    {
        aux = aux->prox;
    }
    if(aux != NULL)
        mostrarPessoa(*aux);
    else
        printf("pessoa nao encontrada.\n");
}

Pessoa *removerPessoa(Pessoa *lista, int op)
{
    if(lista == NULL)
        printf("lista esta vazia.\n");
    
    Pessoa *atual = lista;
    Pessoa *anterior = NULL;

    //caso for a primeira pessoa
    if(atual != NULL && atual->id == op)
    {
        lista = atual->prox;
        free(atual);
        printf("pessoa removida.\n");
        return lista;
    }


    while(atual != NULL && atual->id != op)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL)
        printf("pessoa nao encontrada.\n");
    
    if(anterior != NULL)
        anterior->prox = atual->prox;
    free(atual);
    printf("pessoa removida.\n"); 
    return lista;
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