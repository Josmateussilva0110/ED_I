#include <stdio.h>
#include <string.h>
#include <ctype.h>

char vogais[] = {'a','e','i','o','u','A','E','I','O','U'};
int tam = 10;

void cont(char *string1, char *string2, int *cont, int *v1, int *v2)
{
    int i = 0;
    int cont1 = 0, cont2 = 0;
    while(string1[i] != '\0')
    {
        if(isupper(string1[i]))
            *v1 += 1;
        for(int j = 0; j < tam; j++)
        {
            if(string1[i] == vogais[j])
                cont1 += 1;
        }
        i++;
    }
    int j = 0;
    while(string2[j] != '\0')
    {
        if(isupper(string2[j]))
            *v2 += 1;
        for(int i = 0; i < tam; i++)
        {
            if(string2[j] == vogais[i])
                cont2 += 1;
        }
        j++;
    }

    *cont = cont1 + cont2;
}

int main()
{
   char string[] = "mAteuS";
   char string2[] = "sILva";
   int result = 0, cont1 = 0, cont2 = 0;
   cont(string, string2, &result, &cont1, &cont2);
   printf("quantidade de vogais das duas strings = %d\n",result);
   printf("quantidade de maiusculas em string1 = %d\n",cont1);
   printf("quantidade de maiusculas em string2 = %d\n",cont2);
}