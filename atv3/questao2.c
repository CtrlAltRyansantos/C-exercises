#include <stdio.h>

int main(){

    int n, f, i = 1, j = 0, soma;

    printf("Digite o valor n (inteiro positivo maior que 0)");
    scanf("%d", &n);


    while( j < n){
        printf("%d ", j);
        soma = i + j;
        i = j;
        j = soma;
        
    }
    
    return 0;
}