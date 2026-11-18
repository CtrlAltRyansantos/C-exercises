#include <stdio.h>

int main(){
    float num1,num2;

    printf("digite o dividendo \n");
    scanf("%f", &num1);
    printf("Digite um divisor diferente de 0 ");
    scanf("%f",&num2);
    if( num2 == 0){
        printf("Divisao por zero nao permitida. \nPrograma encerrado");
        return 0;
    }

    printf("resultado da divisao %.2f",(num1/num2));
    return 0;
}
