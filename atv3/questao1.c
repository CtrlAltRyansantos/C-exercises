#include <stdio.h>

int main(){
    int primos = 0, n, i = 2, j = 2;

    printf("Digite a quantidade de primos desejada: ");
    scanf("%d", &n);

    while(n < 0){
        printf("Digite um n valido \n");
        scanf("%d", &n);
    }

    while(primos < n){
        if(i % 2 == 0 && i != 2){
            i++;
        }
        else{
            if(i == 2 || i == 3 || i == 5 || i == 7){
                primos++;
                printf("%d \n", i);
                i++;
            }
            else if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0){;
                i++;
            }
            else {
                    j = 2;

                    while (i >= j && i % j != 0) {
                        j++;
                    }

                    if (i == j) {
                        primos++;
                        printf("%d\n", i);
                    }

                    i++;
                }


        }
        


    }
    return 0;
}