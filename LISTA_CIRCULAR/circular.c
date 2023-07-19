#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id, idade;
    float altura;
    char nome[100];
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
}Lista;


void criar(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserir_inicio(Lista *lista)
{
    printf("dentro da funcao inicio\n");
    No *new = (No*) malloc(sizeof(No));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    new->prox = lista->inicio;
    lista->inicio = new;
    if(lista->fim == NULL)
        lista->fim = new;
    lista->fim->prox = lista->inicio;
}

void inserir_fim(Lista *lista)
{
    printf("dentro da funcao fim\n");
    No *new = (No*) malloc(sizeof(No));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    if(lista->inicio == NULL)
    {
        lista->inicio = new;
        lista->fim = new;
        lista->fim->prox = lista->inicio;
    }
    else
    {
        new->prox = lista->inicio;
        lista->fim->prox = new;
        lista->fim = new;
    }
}

void inserir_ordenado(Lista *lista)
{
    No *aux;
    No *new = (No*) malloc(sizeof(No));
    scanf("%d", &new->idade);
    scanf("%d", &new->id);
    scanf("%f", &new->altura);
    scanf("%s", new->nome);
    if(lista->inicio == NULL)
    {
        new->prox = lista->inicio;
        lista->inicio = new;
        if(lista->fim == NULL)
            lista->fim = new;
        lista->fim->prox = lista->inicio;
    }
    else if(new->idade < lista->inicio->idade)
    {
        new->prox = lista->inicio;
        lista->inicio = new;
        if(lista->fim == NULL)
            lista->fim = new;
        lista->fim->prox = lista->inicio;
    }
    else
    {
        aux = lista->inicio;
        while(aux->prox != lista->inicio && new->idade > aux->prox->idade)
            aux = aux->prox;
        if(aux->prox == lista->inicio)
        {
            if(lista->inicio == NULL)
            {
                lista->inicio = new;
                lista->fim = new;
                lista->fim->prox = lista->inicio;
            }
            else
            {
                new->prox = lista->inicio;
                lista->fim->prox = new;
                lista->fim = new;
            }
        }
        else
        {
            new->prox = aux->prox;
            aux->prox = new;
        }
    }
}

void imprimir(Lista lista)
{
    No *aux = lista.inicio;
    if(aux)
    {
        do{
            printf("idade = %d ", aux->idade);
            printf("id = %d ", aux->id);
            printf("altura = %.2f ", aux->altura);
            printf("nome = %s ", aux->nome);
            printf("-----> ");
            aux = aux->prox;
        }while(aux != lista.inicio);
    }
    printf("\n\n");
}

No *buscar(Lista *lista, int id)
{
    No *aux = lista->inicio;
    if(aux)
    {
        do{
            if(aux->id == id)
                return aux;
            aux = aux->prox;
        }while(aux != lista->inicio);
    }
    printf("pessoa nao encontrada.\n");
}

void exibir_um(No *lista)
{
    printf("idade = %d\n", lista->idade);
    printf("id = %d\n", lista->id);
    printf("altura = %.2f\n", lista->altura);
    printf("nome = %s\n", lista->nome);
}

No *remover(Lista *lista, int id)
{
    No *aux, *remover = NULL;
    if(lista->inicio)
    {
        if(lista->inicio == lista->fim && lista->inicio->id == id)
        {
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        else if(lista->inicio->id == id)
        {
            remover = lista->inicio;
            lista->inicio = remover->prox;
            lista->fim->prox = lista->inicio;
        }
        else
        {
            aux = lista->inicio;
            while(aux->prox != lista->inicio && aux->prox->id != id)
                aux = aux->prox;
            if(aux->prox->id == id)
            {
                if(lista->fim == aux->prox)
                {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                    lista->fim = aux;
                }
                else
                {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                }
            }
        }
    }
    printf("pessoa removida.\n");
    return remover;
}