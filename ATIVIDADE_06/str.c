#include <stdlib.h>
#include "str.h"
#include <stdio.h>

char *lerStr()
{
    char *str = (char*) malloc(sizeof(char) * 300);
    printf("informe uma string: ");
    scanf(" %[^\n]", str);
    return str;
}

int tamanhoStr(char *str)
{
    int cont = 0;
    while(str[cont] != '\0')
    {
        cont++;
    }
    return cont;
}

int comparar(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int valid = 1;
    while(str1[i] != '\0')
    {
        i++;
    }
    while(str2[j] != '\0')
    {
        j++;
    }
    if(i != j)
        return 0;
        
    else
    {
        for(int size = 0; size < i; size++)
        {
            for(int size1 = 0; size1 < j; size1++)
            {
                if(str2[size1] != str1[size])
                {
                    valid = 0;
                    break;
                }
            }
        }
    }
    if(valid)
        return 1;
}

char *concatenar(char *str1, char *str2)
{
    int size1 = 0;
    int size2 = 0;
    int size3 = 0;
    while(str1[size1] != '\0')
    {
        size1++;
    }
    while(str2[size2] != '\0')
    {
        size2++;
    }
    int sun = size1 + size2;
    char *str3 = malloc(sun * sizeof(char));
    while(str1[size3] != '\0')
    {
        str3[size3] = str1[size3];
        size3++;
    }
    int w = 0;
    while(str2[w] != '\0')
    {
        str3[size3] = str2[w];
        size3++;
        w++;
    }
    return str3;
}

void liberar(char *str)
{
    if (str != NULL)
    {  
        free(str);
        str = NULL; 
    }
}