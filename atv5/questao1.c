#include <stdio.h>

int resto(int dividendo, int divisor);


int main(){
    int dividendo, divisor;
    
    printf("insira o dividendo e divisor (positivos maiores que 0)");
    scanf(" %d %d", &dividendo, &divisor);
    printf(" o resto de %d por %d eh %d", dividendo,divisor, resto(dividendo, divisor));

    return 0;
}


int resto(int dividendo, int divisor){

    if( divisor == 0){
        printf(" Divisao por zero nao suportada");
        return 0;
    }
    if(dividendo < divisor){
        return dividendo;
    }
    else{
        return resto(dividendo - divisor, divisor);
    }

}