#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
    int id, idade;
    float altura;
    char nome[100];
};

void inserirPessoaInicio(Pessoa **lista) // ** usado para na main ser utilizada a informacoes
{
    int qnt;
    printf("quantidade de pessoas: ");
    scanf("%d",&qnt);
    *lista = (Pessoa*) calloc(qnt+1, sizeof(Pessoa));
    for(int i = 0; i < qnt+1; i++)
    {
        (*lista)[i].id = -1; // () precedencia 
    }
    for(int i = 0; i < qnt; i++)
    {
        (*lista)[i].id = i;
        scanf("%d",&(*lista)[i].idade);
        scanf("%f", &(*lista)[i].altura);
        scanf("%s", (*lista)[i].nome);
    }
}

void inserirPessoaFim(Pessoa **lista)// ** usado para na main ser utilizada a informacoes
{
    printf("pessoas no fim:\n");
    int qnt;
    printf("quantidade de pessoas: ");
    scanf("%d",&qnt);
    *lista = (Pessoa*) calloc(qnt+1, sizeof(Pessoa));
    for(int i = qnt+1; i >= 0; i--)
    {
        (*lista)[i].id = -1; // () precedencia 
    }
    for(int i = qnt-1; i >= 0; i--)
    {
        (*lista)[i].id = i;
        scanf("%d",&(*lista)[i].idade);
        scanf("%f", &(*lista)[i].altura);
        scanf("%s", (*lista)[i].nome);
    }
}

int contarPessoasNaLista(Pessoa *lista) 
{
    int ans = 0; 
    int i = 0;
    while(lista[i].id != -1)
    {
        ans++;
        i++;
    }
    return ans;
}

void mostrarPessoa(Pessoa p)
{
    printf("idade = %d\n",p.idade);
    printf("altura = %.2f\n",p.altura);
    printf("nome = %s\n",p.nome);
}

void mostrarTodasPessoas(Pessoa *lista)
{
    int i = 0;
    while(lista[i].id != -1)
    {
        printf("id = %d\n",lista[i].id);
        printf("idade = %d\n",lista[i].idade);
        printf("altura = %.2f\n",lista[i].altura);
        printf("nome = %s\n",lista[i].nome);
        i++;
    }
}

void buscarPessoa(Pessoa *lista)
{
    int op, index = -1, i = 0;
    printf("digite o id que deseja buscar: ");
    scanf("%d",&op);
    while(lista[i].id != -1)
    {
        if(op == lista[i].id)
        {
            index = i;
            break;
        }
        i++;
    }
    if(index != -1)
        mostrarPessoa(lista[index]);
    else
        printf("pessoa nao encontrada.\n");
}

void liberarMemoria(Pessoa *lista)
{
    free(lista);
}

void removerPessoa(Pessoa *lista)
{
    int i = 0, op, index = -1, t = 0;
    printf("digite o id que deseja remover: ");
    scanf("%d",&op);
    while(lista[i].id != -1)
    {
        if(op == lista[i].id)
        {
            index = i;
        }
        i++;
        t++;
    }
    for(int i = index; i < t; i++)
    {
        lista[i] = lista[i+1];
    }
    if(t == 1)
        t+=1;
    t--;
    lista = (Pessoa*) realloc(lista, t * sizeof(Pessoa));
    mostrarTodasPessoas(lista);
}

void inserir(Pessoa **lista)
{
    inserirPessoaInicio(lista);
    int size = contarPessoasNaLista(*lista);
    for(int i = 0; i < size -1; i++)
    {
        for(int j = 0; j < size - i -1; j++)
        {
            if((*lista)[j].idade > (*lista)[j +1].idade)
            {
                Pessoa aux = (*lista)[j];
                (*lista)[j] = (*lista)[j+1];
                (*lista)[j+1] = aux;
            }
        }
    }
}