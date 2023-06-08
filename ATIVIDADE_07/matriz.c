#include <stdlib.h>

typedef struct matriz 
{
    int lin;
    int col;
    float *v;
}Matriz;

Matriz *cria(int m, int n) 
{
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->lin = m;
    matriz->col = n;
    matriz->v = (float*)malloc(m * n * sizeof(float));

    return matriz;
}

void libera(Matriz *mat) 
{
    if (mat != NULL) 
    {
        free(mat->v);
        free(mat);
    }
}
float acessa(Matriz *mat, int i, int j) 
{
    int index = i * mat->col + j;
    return mat->v[index];
}

void atribui(Matriz *mat, int i, int j, float v)
{
    int index = i * mat->col + j;
    mat->v[index] = v;
}
int linhas(Matriz *mat) 
{
    return mat->lin;
}

int colunas(Matriz* mat) 
{
    return mat->col;
}
