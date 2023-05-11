#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x, y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos;

void add(float x, float y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = listaPontos; //aponta pra vazio   
    listaPontos = p; //listaPontos passa a ser o primeiro ponto
}

int main(){
    add(1,5);
    add(2,7);
    add(5,3);

    printf("%0.f",listaPontos->prox->prox->x);

    return 0;
}