#include <stdio.h>

int main()
{
    float tempC;
    printf("Digite a temperatura em grau Celsius: ");
    scanf("%f", &tempC);

    // Ou seja, para que você consiga converter de grau Celsius para Fahrenheit,
    //  basta multiplicar a temperatura em graus Celsius por 1,8 e somar 32.

    const float conversor1 = 1.8;
    const float conversor2 = 32;

    float tempF = tempC * conversor1 + conversor2;
    printf("A temperatura em Fahrenheit e de: %.1f.", tempF);


    return 0;
}