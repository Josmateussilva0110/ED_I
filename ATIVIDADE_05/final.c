#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"

int main()
{
	int num_pessoas;
    float height;
    char name[100];
	printf("Quantas pessoas deseja cadastrar?");
	scanf("%d", &num_pessoas);
	Pessoa *p;
	p = add_pessoa(num_pessoas);
	mostrar_pessoas(p, num_pessoas);
    seach_people(p, 1.78, num_pessoas);
    printf("insira a altura que deseja procurar: ");
    scanf("%f",&height);
    seach_people(p, height, num_pessoas);
    mostrar_pessoas(p, num_pessoas);
    printf("Digite o nome da pessoa que deseja remover: ");
    scanf(" %[^\n]", name);
    remover_pessoa(p, &num_pessoas, name);
    mostrar_pessoas(p, num_pessoas);
	return 0;
}