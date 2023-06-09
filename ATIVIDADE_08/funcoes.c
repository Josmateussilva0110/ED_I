#include <stdlib.h>

typedef struct matriz 
{
    int lin;
    int col;
    float *v;
}Matriz;

Matriz *cria(int m, int n)
{
    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
    mat->lin = m;
    mat->col = n;
    mat->v = (float*) malloc(m * n * sizeof(float));
    return mat;
}

void atribui(Matriz *mat, int i, int j, float v)
{
    int index = i * mat->col + j;
    mat->v[index] = v; 
}

void print(Matriz *mat)
{
    for(int i = 0; i < mat->lin; i++)
    {
        for(int j = 0; j < mat->col; j++)
        {
            int index = i * mat->col + j;
            float value = mat->v[index];
            printf("%.2f ",value);
        }
        printf("\n");
    }
}

float acessa (Matriz* mat, int i, int j)
{
    int index = i * mat->col + j;
    return mat->v[index];
}

void libera (Matriz* mat)
{
    if(mat != NULL)
    {
        free(mat->v);
        free(mat);
    }
}

int linhas (Matriz* mat)
{
    return mat->lin;
}

int colunas (Matriz* mat)
{
    return mat->col;
}