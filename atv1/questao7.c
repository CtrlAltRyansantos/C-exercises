#include <stdio.h>


int main() {
    int tempoAtraso;
    float valorOriginal, valorCorrigido, taxa;
    printf("Digite o valor original da prestacao \n");
    scanf("%f",&valorOriginal);
    printf("Digite o tempo de atraso (em meses completos) \n");
    scanf("%d",&tempoAtraso);
    printf("Digite a taxa mensal de juros (em decimal)\n");
    scanf("%f", &taxa);

    valorCorrigido = valorOriginal + (valorOriginal * (taxa/ 100)* tempoAtraso);

    printf("O valor corrigido eh: R$%.2f", valorCorrigido);

    return 0;
}