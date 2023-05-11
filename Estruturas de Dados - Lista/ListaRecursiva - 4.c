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
    p->prox = listaPontos;
    listaPontos = p;
}

void imprime(Ponto *p){
    if(p != NULL){
        printf("\n [%.1f, %.1f]", p->x, p->y);
        imprime(p->prox); 
    }
}

int main(){
    add(1,5);
    add(2,4);
    add(17,8);
    
    Ponto *auxLista = listaPontos;
    imprime(auxLista);


    return 0;
}