#include <stdio.h>

int main(){
    int n, i, j, qtdAcertos;
    int sorteados[6], acertos[6], cartela[15];


    printf("Digite a quantidade de numeros da cartela (6 a 15): ");
    scanf("%d", &n);

    printf("Digite os numeros da cartela:\n");

    for (i = 0; i < n; i++){
        scanf("%d", &cartela[i]);
    }

    printf("Digite os 6 numeros sorteados:\n");
    for (i = 0; i < 6; i++){
        scanf("%d", &sorteados[i]);
    }

    qtdAcertos = 0;

    for (i = 0; i < n; i++){
        for (j = 0; j < 6; j++){
            if (cartela[i] == sorteados[j])
            {
                acertos[qtdAcertos] = cartela[i];
                qtdAcertos++;
            }
        }
    }

    printf("\nQuantidade de acertos: %d\n", qtdAcertos);

    if (qtdAcertos > 0){
        printf("numeros acertados: ");

        for (i = 0; i < qtdAcertos; i++){
            printf("%d ", acertos[i]);
        }

        printf("\n");
    }
    else{
        printf("nenhum numero acertado.\n");
    }

    if (qtdAcertos == 6){
        printf("voce acertou tudo mega-sena !\n");
    }
    else if (qtdAcertos == 5){
        printf("voce fez uma quina !\n");
    }
    else if (qtdAcertos == 4){
        printf("voce fez uma quadra !\n");
    }
    else{
        printf("voce acertou entre 1 e 3 numeros \n");
    }

    return 0;
}
