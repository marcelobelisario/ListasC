#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x, y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos; // aponta para o inicio da lista

void adiciona_inicio(float x, float y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

void adiciona_fim(float x, float y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->prox = NULL;
    if(listaPontos == NULL){
        listaPontos = p;
    }else{
        Ponto *listaAux = listaPontos;
        while(listaAux->prox != NULL){
            listaAux = listaAux->prox;
        }
        listaAux->prox = p;
    }
}

void imprime(Ponto *p){
    if(p != NULL){
        printf("\n [%.1f, %.1f]", p->x, p->y);
        imprime(p->prox); 
    }
}

int main(){
    adiciona_inicio(1,5);
    adiciona_inicio(2,7);
    adiciona_inicio(5,3);
    adiciona_fim(1,1);
    adiciona_fim(8,8);


    Ponto *auxLista = listaPontos;
    imprime(auxLista);


    return 0;
}