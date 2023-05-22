#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print_matrix(int ***array, int size);
void clear_matrix(int ***array, int size);
void creat_circle(int ***array, int size, int radius);


int main()
{
    int tam, i, j;
    int ***mat;
    printf("tamanho da matriz: ");
    scanf("%d",&tam);
    mat = (int***) calloc(tam, sizeof(int**));
    for(i = 0; i < tam; i++)
    {
        mat[i] = (int**) calloc(tam, sizeof(int*));
        for(j = 0; j < tam; j++)
        {
            mat[i][j] = (int*) calloc(tam, sizeof(int));
        }
    }
    int radius = tam / 2;
    creat_circle(mat, tam, radius);
    print_matrix(mat, tam);
    clear_matrix(mat, tam);
}

void print_matrix(int ***array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                printf("%d ",array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void clear_matrix(int ***array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

void creat_circle(int ***array, int size, int radius)
{
    int i, j, k;
    double distance;
    int center_x = size / 2;
    int center_y = size / 2;
    int center_z = size / 2;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            for(k = 0; k < size; k++)
            {
                distance = sqrt((i - center_x) * (i - center_x) + (j - center_y) * (j - center_y) + (k - center_z) * (k - center_z));
                if(distance <= radius)
                    array[i][j][k] = 2;
                else
                    array[i][j][k] = 0;
            }
        }
    }
}