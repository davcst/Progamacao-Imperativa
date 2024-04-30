#include <stdio.h>

int main()
{
    printf("CONVERSOR DE REAL PARA DOLAR \n \n");

    float valorReal;
    printf("Digite o valor em reais: ");
    scanf("%f", &valorReal);

    const float valorDolar = 5;
    
    float valorNovo = valorReal * valorDolar;

    printf("O valor em dolares e $%.2f.", valorNovo);

    return 0;
}