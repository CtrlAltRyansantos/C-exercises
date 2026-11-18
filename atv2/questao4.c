#include <stdio.h>

int main(){
    int dia, mes, ano, dian, mesn, anon, idade;

    printf("Digite dia mes e ano atual \n");
    scanf("%d %d %d",&dia,&mes,&ano);
    if(dia <= 0 || dia > 31 || mes <= 0 || mes >12 || ano < 0){
        printf("Digite uma data valida \n");
        return 0;
    }

    printf("Digite dia mes e ano de nascimento \n");
    scanf("%d %d %d",&dian,&mesn,&anon);
    if(dian <= 0 && dian > 31 || mesn <= 0 && mesn >12 || anon < 0){
        printf("Digite uma data de nascimento valida \n");
        return 0;
    }

    idade = ano - anon -1;
    if((dia >= dian && mes == mesn)|| mes> mesn){
      idade++;
    }

    if(idade >= 16){
        printf(" o caba pode votar %d, anos", idade);
    }
    else{
        printf(" o caba pode nao votar %d, anos", idade);
    }
    return 0;
}