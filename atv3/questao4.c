#include <stdio.h>

int main(){
    int n, i = 2, j, primo = 0;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    while(n < 0){
        printf("Digite um n valido \n");
        scanf("%d", &n);
    }

      while(i < n){
        if(i % 2 == 0 && i != 2){
            i++;
        }
        else{
            if(i == 2 || i == 3 || i == 5 || i == 7){;
                primo = i;
                i++;
            }
            else if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0){;
                i++;
            }
            else {
                    j = 2;
                    while (i >= j && i % j != 0 && j < n) {
                        j++;
                    }

                    if (i == j) {
                        primo = i;
                    }
                    i++;
                }
        }
    }
    printf("o maior primo menor que %d eh %d",n, primo);
    return 0;
}