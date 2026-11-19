#include <stdio.h>

int ChecaPg();

int main(){
    
    if(ChecaPg()){
        printf("eh uma PG \n");
    }
    else printf(" Nao eh uma PG \n");

    return 0;
}

int ChecaPg(){
    int n, i, vetor[1000];
    float razao;

    printf("Digite a quantidade de elementos da sua pg (0 < N < 1000) ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Digite o elemento da posicao %d da sua pg ", i + 1);
        scanf("%d", &vetor[i]);

        if(i > 1){
            razao = vetor[1]/vetor[0];
            if(vetor[i]/vetor[i -1] != razao){
                return 0;
        }
        }

    }
    return 1;

}