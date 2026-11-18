#include <stdio.h>



int main(){
    int n, invertido;

    printf("digite o valor a ser invertido (inteiro ate 10 digitos) \n");
    scanf("%d",&n);

   
    do{
        printf("digite um valor valido \n");
        scanf("%d",&n);
    }while(n > 9999999999 || n < 0);
   
    while (n > 0) {
    invertido = invertido * 10 + n % 10;
    n = n / 10;
}   
    printf("o numero invertido eh %d \n", invertido); 
    return 0;
}