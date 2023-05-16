#include <stdio.h>
#include <string.h>

void verificar(char *array1, char *array2);

int main()
{
    int tam;
    scanf("%d",&tam);
    char string1[tam];
    int tam2;
    scanf("%d",&tam2);
    char string2[tam2];
    scanf("%s", string1);
    scanf("%s", string2);
    verificar(string1, string2);
}

void verificar(char *array1, char *array2) 
{
    int tam1 = strlen(array1);
    int tam2 = strlen(array2);
    int valid = 0,i,j;
    for (i = 0; i <= tam1 - tam2; i++) 
    {
        for (j = 0; j < tam2; j++) 
        {
            if (*(array1 + i + j) != *(array2 + j)) 
            {
                break;
            }
        }
        if (j == tam2) 
        {
            valid = 1;
            break;
        }
    }
    if(valid) 
    {
        printf("A segunda string esta contida na primeira.\n");
    } 
    else 
    {
        printf("A segunda string nao esta contida na primeira.\n");
    }
}