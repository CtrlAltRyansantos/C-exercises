#include <stdio.h>

int main(){
    int soma = 0, somaelse = 0, contador, numero, contadorelse;
    float media, mediaelse;

    do{ 
        printf("Digite 10 numeros inteiros divisiveis por 3, faltam %d numeros \n", 10 - contador);
        scanf("%d", &numero);
        if( numero % 3 == 0){
            contador++;
            soma = soma + numero;
        }
        else{
            contadorelse++;
            somaelse = somaelse + numero;
        }

    }while (contador < 10);

    media = soma/contador;
    mediaelse = somaelse/contadorelse;

    printf("A media dos multiplos de 3: %.2f, media dos outros %.2f ",media, mediaelse);
    
    return 0;
}