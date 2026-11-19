#include <stdio.h>

int main(){
    int x,y,z,i,j,k;
    int A[20][20], B[20][20], C[20][20];

    printf("Digite x, y e z: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Digite os valores da matriz A:\n");
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os valores da matriz B:\n");
    for (i = 0; i < y; i++) {
        for (j = 0; j < z; j++){
            scanf("%d", &B[i][j]);
        }
    }


    for (i = 0; i < x; i++){
        for (j = 0; j < z; j++){
            C[i][j] = 0;

            for (k = 0; k < y; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    printf("matriz C \n");

    for (i = 0; i < x; i++){
        for (j = 0; j < z; j++){
            printf("%d ", C[i][j]);
        }
    }

    return 0;

}