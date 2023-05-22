#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void occupy(int **array, int v1, int v2);
void print_matrix(int **array, int tam1, int tam2);
void restart(int ***mat, int m, int n);
int check_collision(int **array, int tam1, int tam2, int v1, int v2);


int main()
{
    int m, n, i, **mat, op, x, y;
    int has_collision, not_collision;
    printf("Tamanho do tabuleiro (m/n): ");
    scanf("%d %d", &m, &n);
    restart(&mat, m, n);
    srand(time(NULL));
    while (1)
    {
        has_collision = 0;
        not_collision = 0;
        for (i = 0; i < 10; i++)
        {
            x = rand() % m;
            y = rand() % n;
            if (check_collision(mat, m, n, x, y))
            {
                occupy(mat, x, y);
                not_collision++;
            }
            else
                has_collision++;
        }
        print_matrix(mat, m, n);
        printf("Os carros colidiram %d vezes\n", has_collision);
        printf("Os carros nao colidiram %d vezes\n", not_collision);
        restart(&mat, m, n);
        printf("Deseja continuar (1 - Sim / 0 - Nao): ");
        scanf("%d", &op);
        if (!op)
            break;
    }
    for (i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void occupy(int **array, int v1, int v2)
{
    array[v1][v2] = 2;
}

void print_matrix(int **array, int tam1, int tam2)
{
    for (int i = 0; i < tam1; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void restart(int ***mat, int m, int n)
{
    *mat = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        (*mat)[i] = (int *)calloc(n, sizeof(int));
    }
}

int check_collision(int **array, int tam1, int tam2, int v1, int v2)
{
    int min_dist;
    if (tam1 < tam2) 
    {
        min_dist = tam1 / 2;
    } 
    else 
    {
        min_dist = tam2 / 2;
    }
    for (int i = v1 - min_dist; i <= v1 + min_dist; i++)
    {
        for (int j = v2 - min_dist; j <= v2 + min_dist; j++)
        {
            if (i >= 0 && i < tam1 && j >= 0 && j < tam2)
            {
                if (array[i][j] == 2)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
