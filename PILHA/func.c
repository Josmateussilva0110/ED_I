#include <stdio.h>
#include <stdlib.h>


typedef struct Lista Lista;
typedef struct Pilha Pilha;


struct Lista
{
    float info;
    Lista *prox;
};


struct Pilha
{
    Lista *prim;
};


Pilha *criar_pilha()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha *p, float v)
{
    Lista *n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

void imprimir(Pilha *p)
{
    Lista *aux = p->prim;
    while(aux != NULL)
    {
        printf("%.2f ",aux->info);
        aux = aux->prox;
    }
}

int pilha_pop(Pilha *p)
{
    Lista *t;
    float v;
    if(p->prim == NULL)
    {
        printf("pilha esta vazia.\n");
        return 0;
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    printf("valor removido.\n");
    return 1;
}