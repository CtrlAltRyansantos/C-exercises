#include <stdio.h>

int main(){
    int ano;

    printf("digite o ano \n");
    scanf("%d",&ano);

    if(ano < 1752){
        printf("Ano nao bissexto");
    }
    else{
        if(ano % 4 == 0 ){
            if(ano % 100 == 0 ){
                if (ano % 400 == 0){
                printf("O ano e bissexto");
                }
                else { printf("Nao e bissexto");
                }}
             
            else{
              printf("O ano e bissexto");
            }
        }
    }
}