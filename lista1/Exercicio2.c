#include <stdio.h>

int main()
{
    float peso;
    printf("digite seu peso(kg): ");
    scanf("%f", &peso);

    float pesoIdeal;
    printf("digite seu peso ideal(kg): ");
    scanf("%f", &pesoIdeal);

    float perdaMensal;
    printf("digite sua perda mensal(kg): ");
    scanf("%f", &perdaMensal);

    float resultado = (peso - pesoIdeal) / perdaMensal;
    printf("voce alcancara seu peso ideal em %.0f meses.", resultado);

    return 0;
}