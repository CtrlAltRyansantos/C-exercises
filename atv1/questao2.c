#include <stdio.h>

int main(){
    int idade;
    int segundosNoAno, batimentos;
    segundosNoAno = (365 * 24 * 60 * 60);

    printf("Digite a Idade (em anos completos)");
    scanf("%d", &idade);
    batimentos = idade * segundosNoAno;
    
    printf("O coracao bateu aproximadamente %d vezes",batimentos);

    return 0;
}
