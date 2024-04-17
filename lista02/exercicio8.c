#include <stdio.h>




    void conversor(float A, float B, float *R1){
        *R1 = A * B;
        return;
    }


int main()
{
    printf("CONVERSOR DE REAL PARA DOLAR \n \n");

    float valorReal;
    printf("Digite o valor em reais: ");
    scanf("%f", &valorReal);

    const float valorDolar = 5;
    const float valorEuro = 5.5;
    float resultado;

    conversor(valorReal, valorDolar, &resultado);
    printf("O valor em dolares e $%.2f.\n", resultado);

    conversor(valorReal, valorEuro, &resultado);
    printf("O valor em euro e $%.2f.\n", resultado);    

    
    // float valorNovoD = valorReal * valorDolar;
    // float valorNovoE = valorReal * valorEuro;

    // printf("O valor em dolares e $%.2f.", valorNovoD);
    // printf("O valor em dolares e $%.2f.", valorNovoE);

    return 0;
}