#include <stdio.h>
#include <math.h>

int main(){

    printf("Calculo da area do circulo\n");
    printf("--------------------------\n");

    float raioC;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raioC);

    //float areaC =  M_PI * (raioC * raioC);
    float areaC = M_PI * pow(raioC, 2);

    printf("A area do circulo e %.3f", areaC);
    

    return 0;
}