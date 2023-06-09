#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

struct pixel
{
	int valor, x, y;
};

struct imagem
{
	Pixel *pixels;
	int largura, altura;
};

Imagem *criarImagem(int largura, int altura)
{
    //alocando memoria para a estrutura imagem
    Imagem *img = (Imagem*) malloc(sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    //alocando memoria na ponteiro pixels
    img->pixels = (Pixel*) malloc(altura * largura * sizeof(Pixel));
    return img;
}

void preencherImagem(Imagem *img)
{
    for(int i = 0; i < img->altura * img->largura; i++)
    {
        // posicionar o pixel na matriz que vai de 0 a img-> altura - 1
        img->pixels[i].x = i % img->largura;
        // posicionar o pixel na matriz que vai de 0 a img-> largura -1
        img->pixels[i].y = i / img->largura;
        img->pixels[i].valor = 0;
    }
}

void imprimirImagem(Imagem *img)
{
    for(int i = 0; i < img->altura; i++)
    {
        for(int j = 0; j < img->largura; j++)
        {
            int index = i * img->largura + j;
            printf("%d ",img->pixels[index].valor);
        }
        printf("\n");
    }
}

void liberarImagem(Imagem *img)
{
    free(img->pixels);
    free(img);
}

 void setPixelValue(Imagem *img, int y, int x, int valor)
 {
    int index = y * img->largura + x;
    img->pixels[index].valor = valor;
 }

 int getPixelValue(Imagem *img, int y, int x)
 {
    int index = y * img->largura + x;
    return img->pixels[index].valor;
 }