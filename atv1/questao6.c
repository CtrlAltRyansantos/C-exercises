#include <stdio.h>

int main(){
    float valorCompra, taxaDia, ICMS, lucroEmpresa, valorFinal;

    printf("Digite o valor da compra \n");
    scanf("%f", &valorCompra);
    printf("Digite a taxa do dia \n");
    scanf("%f", &taxaDia);
    printf("Digite o ICMS \n");
    scanf("%f", &ICMS);
    printf("Digite o lucro da empresa \n");
    scanf("%f", &lucroEmpresa);

    ICMS = valorCompra * ICMS / 100;
    lucroEmpresa = valorCompra * lucroEmpresa / 100;

    valorFinal = valorCompra + ICMS + lucroEmpresa;

    printf("Valor a ser pago: R$%.2f\n", valorFinal);

    return 0;
}