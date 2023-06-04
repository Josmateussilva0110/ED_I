#include "str.c"
#include <stdlib.h>
#include <stdio.h>
#include "str.h"

int main()
{
    char *array = malloc((300) * sizeof(char));
    char *array2 = malloc(300 * sizeof(char));
    array = lerStr();
    array2 = lerStr();
    printf("nomes digitados:\n%s\n%s\n",array, array2);
    int tam = tamanhoStr(array);
    int tam2 = tamanhoStr(array2);
    int comp = comparar(array, array2);
    int tam3 = tam + tam2;
    char *result = malloc(tam3 * sizeof(char));
    result = concatenar(array, array2);
    printf("concatenada = %s\n",result);
    if(comp)
        printf("as strings sao iguais\n");
    else
        printf("as strings sao diferentes\n");
    liberar(array);
    liberar(array2);
    liberar(result);
}