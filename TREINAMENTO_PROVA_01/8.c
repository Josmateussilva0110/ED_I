#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void primo(int n, int *p1, int *p2);

int main()
{
    int n, p1, p2;
    scanf("%d",&n);
    primo(n, &p1, &p2);
    printf("%d\n",p1);
    printf("%d\n",p2);
}

void primo(int n, int *p1, int *p2)
{
    *p1 = -1;
    *p2 = -1;
    int aux = 0;
    int valid;
    int *result = NULL;
    for(int j = 2; j < n; j++)
    {
        valid = 1;
        for(int i = 2; i < j; i++)
        {
            if(j % i == 0)
            {
                valid = 0;
                break;
            }
        }
        if(valid)
        {
            aux++;
            result = (int*) realloc(result, aux * sizeof(int));
            result[aux - 1] = j;
        }
    }
    if(aux > 0)
    {
        *p1 = result[aux -1];
        *p2 = result[0];
    }
    free(result);
}
