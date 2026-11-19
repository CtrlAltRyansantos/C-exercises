#include <stdio.h>
#include <math.h>

long int fatorial(int n, long int a);

double exponencial(float n, double acumulador, int i);

int main(){

    printf(" %lf", exponencial(3, 1, 1));
    return 0;
}

long int fatorial(int n, long int a){
    if(n <= 1){
        return a;
    }
    else return fatorial(n-1, n * a);
}

double exponencial(float n, double acumulador, int i){
    double quociente;

    quociente = pow(n, i)/fatorial(i, 1);
    if(quociente < 10e-6){
        return acumulador;
    }

    else{
        return exponencial(n, acumulador + quociente, i+1);
    }

}