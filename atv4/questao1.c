#include <stdio.h>
#include <math.h>

float distanciaEuclidiana(float x1, float y1, float z1, float x2,
     float y2, float z2);

int main(){
    float x1,y1,z1,x2,y2,z2,resposta;
    printf("Digite o primeiro ponto (espacado por espaco) \n");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Digite o segundo ponto (espacado por espaco) \n");
    scanf("%f %f %f", &x2, &y2, &z2);
    resposta = distanciaEuclidiana(x1,y1,z1,x2,y2,z2);
    printf("%.2f",resposta);
    return 0;
}

float distanciaEuclidiana(float x1, float y1, float z1, float x2,
     float y2, float z2){ 

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}