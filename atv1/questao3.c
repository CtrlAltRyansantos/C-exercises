#include <stdio.h>
#define pi 3.141592

int main(){
    int custoAluminio = 100;
    float raio, altura, areaLata, valor; 

    printf("digite o raio da lata (em metros) \n");
    scanf("%f",&raio);
    printf("digite a altura da lata (em metros) \n");
    scanf("%f",&altura);
    
    areaLata = (pi* raio*raio *2) + (2* pi * raio * altura);
    valor = areaLata * custoAluminio;
     
    printf("A lata tem %.2fm de area, e custa %.2fR$",areaLata,valor);


    return 0;
}