#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocate(int rows, int cols);
void occupy(FILE *arquivo, int rows, int cols, int **array);
void calculations(int value, int rows, int cols, int **array);
void clear(int **array, int rows);

int main()
{
    int **array;
    int rows, cols;
    int seedx = 690, seedy = 440;
    FILE *arquivo = fopen("input.txt", "r");
    if(arquivo == NULL)
    {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }
    fscanf(arquivo, "%d", &rows);
    fscanf(arquivo, "%d", &cols);
    
    array = allocate(rows, cols);

    occupy(arquivo, rows, cols, array);

    int seedvalue = array[seedy][seedx];
    calculations(seedvalue, rows, cols, array);
    fclose(arquivo);

    FILE *output = fopen("saida.txt","w");
    if(output == NULL)
    {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }
    else
    {
        printf("arquivo de saida criado com sucesso\n");
        fprintf(output, "%d\n", rows);
        fprintf(output, "%d\n", cols);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                fprintf(output, "%d ", array[i][j]);
            }
            fprintf(output, "\n");
        }
    }
    fclose(output);

    clear(array, rows);
    fclose(arquivo);
}

int **allocate(int rows, int cols)
{
    int **array = (int **) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        array[i] = (int*) malloc(cols * sizeof(int));
    }
    return array;
}

void occupy(FILE *arquivo, int rows, int cols, int **array)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            fscanf(arquivo, "%d", &array[i][j]);
        }
    }
}

void calculations(int value, int rows, int cols, int **array)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(abs(array[i][j] - value) < 100)
                array[i][j] = 255;
            else
                array[i][j] = 0;
        }
    }
}

void clear(int **array, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}