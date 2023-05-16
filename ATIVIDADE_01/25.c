#include <stdio.h>
#include <stdlib.h>

void read_notes(float *note1, float *note2);
void media(float n1, float n2, float *media, float *ponderada);

int main()
{
    float note1, note2, medi, ponderada;
    read_notes(&note1, &note2);
    printf("mota 1 = %.2f\n",note1);
    printf("nota 2 = %.2f\n",note2);
    media(note1, note2, &medi, &ponderada);
    printf("media simples = %.2f\n",medi);
    printf("media ponderada = %.2f\n",ponderada);
}
void read_notes(float *note1, float *note2)
{
    while(1)
    {
        printf("nota 1:");
        scanf("%f", note1);
        if(*note1 >= 0.0 && *note1 <= 10)
            break;
        else
            printf("nota invalida!\n");
    }
    while(1)
    {
        printf("nota 2:");
        scanf("%f", note2);
        if(*note2 >= 0.0 && *note2 < 10)
            break;
        else
            printf("nota invalida!\n");
    }
}

void media(float n1, float n2, float *media, float *ponderada)
{
    *media = (n1 + n2) / 2;
    *ponderada = (n1 + (n2*2)) / 3;
}