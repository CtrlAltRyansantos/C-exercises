#include <stdio.h>

int main(){
    float total, fixo, kwhEco, kwhNorm;
    
    printf("Digite a quantidade de Kwh consumida durante o período econômico \n ");
    scanf("%f", &kwhEco);
    
    printf("Digite a quantidade de Kwh consumida durante o período normal \n ");
    scanf("%f", &kwhNorm);
    
    fixo = 10;
    total = 0.1 * kwhEco + 0.13 * kwhNorm + fixo;
    
    printf("Valor a ser pago R$%.2f\n", total);
    return 0;
}