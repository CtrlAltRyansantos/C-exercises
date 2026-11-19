#include <stdio.h>

int MDC(int x, int y);

int main(){
    int x,y,z,resposta;
    printf("Digite x y z inteiros e espacados por espaco \n");
    scanf("%d %d %d", &x, &y, &z);
    resposta = MDC(MDC(x,y),z);

    printf("o MDC de %d %d e %d eh %d",x,y,z, resposta);
    return 0;

}

int MDC(int x, int y){
    int resto;

    resto = x % y;
    if(resto == 0){
        return y;
    }
    else{
        return MDC(y, resto);
    }

}