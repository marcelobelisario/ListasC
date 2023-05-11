#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int multiplicador){
    if(multiplicador == 1){
        return base;
    }
    return base*potencia(base, multiplicador-1);
}   

int main(){
    int num = potencia(2,4); //16
    printf("\n Potencia: %d", num);


    return 0;
}