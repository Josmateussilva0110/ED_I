#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char vogais[] = {'a','e','i','o','u'};

int main()
{
    char *string = (char*) malloc(100 * sizeof(char));
    scanf("%[^\n]s", string);
    int size = strlen(string);
    char *array = (char*) realloc(NULL, (size + 1) * sizeof(char));
    for(int i = 0; i < size; i++)
    {
        *(array + i) = *(string + i);
    }
    free(string);
    char *P = array;
    int i = 0;
    while(P[i] != '\0')
    {
        if(*(P + i) == vogais[0])
            *(P + i) = vogais[4];
        if(*(P + i) == vogais[1])
            *(P + i) = vogais[3];
        if(*(P + i) == vogais[2])
            *(P + i) = vogais[4];
        if(*(P + i) == vogais[3])
            *(P + i) = vogais[0];
        if(*(P + i) == vogais[4])
            *(P + i) = vogais[1];
        i++;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%c",*P);
        P++;
    }
    printf("\n");
    free(array);
}