#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;
typedef struct Fila Fila;

struct Lista
{
    float info;
    Lista *prox;
};

struct Fila
{
    Lista *inicio;
    Lista *fim;
};

Fila *criar_fila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void fila_push(Fila *f, float v)
{
    Lista *n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = NULL;

    if (f->fim == NULL) // Se a fila esta vazia
    {
        f->inicio = n;
        f->fim = n;
    }
    else
    {
        f->fim->prox = n;
        f->fim = n;
    }
}

void imprimir(Fila *f)
{
    Lista *aux = f->inicio;
    while (aux != NULL)
    {
        printf("%.2f ", aux->info);
        aux = aux->prox;
    }
}

int fila_pop(Fila *f)
{
    Lista *t;
    float v;
    if (f->inicio == NULL)
    {
        printf("fila esta vazia.\n");
        return 0;
    }
    t = f->inicio;
    v = t->info;
    f->inicio = t->prox;
    free(t);
    printf("valor removido.\n");
    if (f->inicio == NULL) // Se a fila ficou vazia apos a remocao
    {
        f->fim = NULL;
    }
    return 1;
}
