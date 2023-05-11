#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x, y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos; // aponta para o inicio da lista

void imprime(Ponto *p){
    if(p != NULL){
        printf("\n [%.1f, %.1f]", p->x, p->y);
        imprime(p->prox); 
    }
}

int tamanho = 0;

void adiciona_posicao(float x, float y, int posicao){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    
    if(posicao>tamanho){
        printf("\n Posicao Invalida!!!");
    }else{
        if(posicao==0){
            p->prox = listaPontos;
            listaPontos = p;
        }else{
            Ponto *listaAux = listaPontos;
            int i=0;
            while(i!=posicao-1){
                listaAux = listaAux->prox;
                i++;
            }
            p->prox = listaAux->prox;
            listaAux->prox = p;
        }
        tamanho++;
    }
}

int main(){
    adiciona_posicao(1,1,0);
    adiciona_posicao(2,4,1);
    adiciona_posicao(4,16,2);
    adiciona_posicao(3,9,2);
    adiciona_posicao(0,0,0);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);


    return 0;
}