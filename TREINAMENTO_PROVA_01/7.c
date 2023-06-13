#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char vogal[] = {'a','e','i','o','u'};

char *vogais(char *string1, char *string2);

int main()
{
    char *string1 = (char*) malloc(50 * sizeof(char));
    char *string2 = (char*) malloc(50 * sizeof(char));
    scanf(" %[^\n]s", string1);
    scanf(" %[^\n]s", string2);
    char *result = (char*) malloc(50 * sizeof(char));
    result = vogais(string1, string2);
    printf("%s\n",result);
    free(string1);
    free(string2);
    free(result);
}

char *vogais(char *string1, char *string2)
{
    int tam1 = strlen(string1);
    int tam2 = strlen(string2);
    char *string3 = NULL;
    int i = 0, cont = 0;
    while(string1[i] != '\0')
    {
        for(int j = 0; j < 5; j++)
        {
            if(string1[i] == vogal[j])
            {
                cont++;
                string3 = (char*) realloc(string3, cont * sizeof(char));
                string3[cont -1] = string1[i];
            }
        }
        i++;
    }
    int j = 0;
    while(string2[j] != '\0')
    {
        for(int i = 0; i < 5; i++)
        {
            if(string2[j] == vogal[i])
            {
                cont++;
                string3 = (char*) realloc(string3, cont * sizeof(char));
                string3[cont - 1] = string2[j];
            }
        }
        j++;
    }
    return string3;
}
