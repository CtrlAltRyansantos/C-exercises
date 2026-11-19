#include <stdio.h>
#include <math.h>

long int fatorial(int x);
float exponencial(float n);

int main(){
    float resposta, n;

    printf("Digite o valor \n");
    scanf("%f", &n);
    resposta = exponencial(n);
    printf("%f \n", resposta);

    return 0;
}

long int fatorial(int n){
    if(n == 1){
        return 1;
    }
    return n * fatorial(n-1);
}

float exponencial(float x){
    float resposta = 1, quociente = 1;
    int i = 1;

    while (fabs(quociente) > 1e-6)
    {
        quociente = (pow(x,i) / fatorial(i));
        resposta = resposta + quociente;
        i++;

    }
    return resposta;
    
}
