#include <stdio.h>
#include <math.h>

int main(){

    printf("Calculo do IMC\n");
    printf("--------------------------\n");

    float massa;
    printf("Digite o peso em kg: ");
    scanf("%f", &massa);

    float altura;
    printf("Digite a altura em m: ");
    scanf("%f", &altura);
    printf("--------------------------\n");

    float IMC = massa / (pow(altura, 2));

    // if(IMC < 0)
    //     printf("O seu IMC e %.1f\n", IMC);

    printf("O seu IMC e %.1f\n", IMC);

    if(IMC < 16.9 && IMC < 0)
        printf("Voce esta muito abaixo do peso");
    else if(IMC >= 17 && IMC <= 18.49)
        printf("Voce esta abaixo do peso");
    else if(IMC >= 18.5 && IMC <= 24.99)
        printf("Voce esta abaixo do peso");
    else if(IMC >= 25 && IMC <= 29.99)
        printf("Voce esta acima do peso");
    else if(IMC >= 30 && IMC <= 34.99)
        printf("Voce esta com obesidade grau 1");
    else if(IMC >= 35 && IMC <= 40)
        printf("Voce esta com obesidade grau 2");
    else if(IMC > 40)
        printf("Voce esta com obesidade grau 3");
    else
        printf("Erro");

    

    return 0;
}