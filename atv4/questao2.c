#include <stdio.h>

int MDC(int x, int y);

int main(){
    int x,y, resposta;
    printf("Digite x e y inteiros e espacados por espaco");
    scanf("%d %d", &x, &y);
    resposta = MDC(x,y);

    printf("o MDC de %d e %d eh %d",x,y,resposta);
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