#include <stdio.h>

int main(){
    float l1, l2, l3, maior;
    
    printf("Digite os 3 lados do triangulo (positivos)\n");
    scanf("%f", &l1);
    maior = l1;
    scanf("%f",&l2);
    if( l2 > maior)
     maior = l2;
    scanf("%f",&l3);
    if(l3 > maior) 
      maior = l3;

    if(l1 <= 0 || l2 <= 0|| l3 <= 0){ 
        printf("Digite valores validos");
    }

    if(maior == l1){ l1 = 0;}
    if(maior == l2){ l2 = 0;}
    if(maior == l3){ l3 = 0;}

    if( maior * maior == l1*l1 + l2*l2 + l3*l3){
        printf("O triangulo e retangulo");
        }
    else{
        printf("O triangulo nao e retangulo");
    }
     return 0;
    }
