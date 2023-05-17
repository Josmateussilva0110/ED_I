#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define RECTANGLE_RATIO 0.5

void createRectangle(int* array);
void createCircle(int* array);
void print_array(int* array);


int main() 
{
    int *array = (int*)calloc(SIZE * SIZE, sizeof(int));
    createRectangle(array);
    createCircle(array);
    print_array(array);
    free(array);
}

void createRectangle(int* array) 
{
    int rectSize = SIZE * RECTANGLE_RATIO;
    int startRow = (SIZE - rectSize) / 2;
    int endRow = startRow + rectSize;
    int startCol = (SIZE - rectSize) / 2;
    int endCol = startCol + rectSize;
    for (int i = startRow; i < endRow; i++) 
    {
        for (int j = startCol; j < endCol; j++) 
        {
            array[i * SIZE + j] = 1;
        }
    }
}

void createCircle(int* array) 
{
    int rectSize = SIZE * RECTANGLE_RATIO;
    int centerX = SIZE / 2;
    int centerY = SIZE / 2;
    int radius = rectSize / 2;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            int distance = sqrt((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY));
            if (distance <= radius) 
            {
                array[i * SIZE + j] = 2;
            }
        }
    }
}

void print_array(int* array) 
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%d ", array[i * SIZE + j]);
        }
        printf("\n");
    }
}