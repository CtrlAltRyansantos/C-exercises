#include <stdio.h>
#include <math.h>

float potencia(float n, int k);

int main(){
    float n, resposta;
    int k;

    printf("Digite o valor da base e do expoente");
    scanf("%f %d", &n, &k);
    resposta = potencia(n, k);
    printf("o resultado eh %.2f, resposta produzida por pow: %2.f ", resposta, pow(n, k));
    
    return 0;
}

float potencia(float n, int k){
    if(k < 1){
        return 1/n * potencia(n, k +1);
    }
    if(k == 1){
        return n;
    }
    else{
        return n * potencia(n, k - 1);
    }

}