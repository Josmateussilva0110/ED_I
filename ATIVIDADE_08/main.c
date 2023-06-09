#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#include "funcoes.c"

int main()
{
	Imagem *img;

	img = criarImagem(3,3);
	preencherImagem(img);
    setPixelValue(img, 0, 0, 5);
    setPixelValue(img, 1, 1, 5);
    setPixelValue(img, 2, 2, 5);
    int a = getPixelValue(img, 1, 1);
    printf("%d\n",a);
    imprimirImagem(img);
    liberarImagem(img);
}