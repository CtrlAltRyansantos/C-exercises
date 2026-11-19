#include <stdio.h>


int main(){

    int n[10000], i = 0, j, k, l, temp = 1;

    printf("Digite os valores (negativo para parar):\n");
    scanf("%d", &temp);

    while (temp >= 0) {
        n[i] = temp;
        i++;

        printf("Valor %d: ", i + 1);
        scanf("%d", &temp);
    }

    for(j=0; j < i; j++){
        for(k=0; k < i; k++){
            if(n[k] > n[j]){
                temp = n[k];
                n[k] = n[j];
                n[j] = temp;

            }
        }
    }

    printf("[");
    for (int l = 0; l < i; l++) {
        if (l > 0) {
            printf(", ");
        }
        printf("%d", n[l]);
    }
    printf("]\n");

    return 0;

}