#include <stdio.h>
#include <math.h>

int palindromo(int n);
int primeiroDigito(int n);
int removeMaiorDigito(int n);

int main(){
    int n;

    printf("Digite o numero a ser checado (inteiro positivo)");
    scanf("%d", &n);
    if(palindromo(n)){
        printf("Eh palindromo");
    }
    else{
        printf("nao eh palindromo");
    }
}

int palindromo(int n){
    
    if(n < 10){
        return 1;
    }
    
    if(n % 10 == primeiroDigito(n)){
        n = removeMaiorDigito(n)/10;
        return palindromo(n);
    }
    else{
        return 0;
    }
}

int primeiroDigito(int n){
    if(n < 10){
        return n;
    }
    else{
        return primeiroDigito(n/10);
    }
}

int removeMaiorDigito(int n){
    int i;
    i = 1;
    while (n > i){
        i = i *10;
    }
    return n - (primeiroDigito(n) * i/10);  
}