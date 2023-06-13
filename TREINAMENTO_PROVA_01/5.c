#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char string[] = "O EXERCICIO E FACIL";
    int *cont = (int*) calloc(256, sizeof(int));
    char *P = string; 
    int i = 0;

    while(P[i] != '\0')
    {
        cont[(int)*P]++;
        P++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(cont[i] > 0)
            printf("%c - %d\n",i, cont[i]);  
    }
    free(cont);
}