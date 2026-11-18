#include <stdio.h>

int main(){
    char nome[50];
    int numeroFilhos, horasTrabalhadas;
    float valorPorHora, salario, gratificacao;
    printf("Digite o nome do funcionario\n");
    scanf("%s",&nome);
    printf("Digite as horas trabalhadas (completas)\n");
    scanf("%d", &horasTrabalhadas);
    printf("Digite o valor por hora trabalhada \n");
    scanf("%f",&valorPorHora);
    printf("Digite o numero de filhos\n");
    scanf("%d",&numeroFilhos);

    salario = horasTrabalhadas * valorPorHora;
    gratificacao = 0;
    if(numeroFilhos > 3){
        gratificacao = salario * (numeroFilhos * 0.03);
        salario = gratificacao + salario;
    };

    printf("Nome: %s, Salario: %.2f, Gratificacao: %.2f",nome,salario,gratificacao);
    return 0;
}