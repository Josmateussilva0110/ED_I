#include "definicoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[100];
    int idade;
    float altura;
};

Pessoa *add_pessoa(int t) 
{
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa) * t);
    for (int i = 0; i < t; ++i)
    {
        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);
        printf("Idade: ");
        scanf("%d", &(p[i].idade));
        printf("Altura: ");
        scanf("%f", &(p[i].altura));
    }
    return p;
    free(p);
}

void mostrar_pessoas(Pessoa *p, int t)
{
    printf("\n");
    printf("DADOS CADASTRADOS:\n");
	for (int i = 0; i < t; ++i)
	{
		printf("Nome: %s\n", p[i].nome);
		printf("Idade: %d\n", p[i].idade);
		printf("Altura: %.2f\n", p[i].altura);
        printf("--------------------------------\n");
	}
}

void seach_people(Pessoa *p, float height, int t)
{
    int valid = 0;
    printf("\n");
    printf("PESSOAS ENCONTRADAS:\n");
    for(int i = 0; i < t; i++)
    {
        if(height == p[i].altura)
        {
            printf("Nome: %s\n", p[i].nome);
		    printf("Idade: %d\n", p[i].idade);
		    printf("Altura: %.2f\n", p[i].altura);
            printf("--------------------------------\n");
            valid = 1;
        }
    }
    if(!valid)
        printf("pessoas nao encontradas.\n");
}

void remover_pessoa(Pessoa *p, int *tamanho, const char *nome) 
{
    int indice = -1;
    
    for (int i = 0; i < *tamanho; i++) 
    {
        if (strcmp(p[i].nome, nome) == 0) 
        {
            indice = i;
            break;
        }
    }
    
    if (indice != -1) 
    {
        // Deslocar as pessoas à direita do índice
        for (int i = indice; i < *tamanho - 1; i++) 
        {
            p[i] = p[i + 1];
        }
        
        (*tamanho)--;
        p = (Pessoa*)realloc(p, sizeof(Pessoa) * (*tamanho));
        
        printf("Pessoa removida com sucesso.\n");
    } 
    else 
    {
        printf("Pessoa não encontrada.\n");
    }
}
