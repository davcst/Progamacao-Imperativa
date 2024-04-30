#include <stdio.h>

int main()
{
    float distancia;
    printf("Qual a distancia a ser percorrida(m)? ");
    scanf("%f", &distancia);

    float velocidade;
    printf("Qual a velocidade media(m/s)? ");
    scanf("%f", &velocidade);

    float tempo = distancia / velocidade;

    printf("O tempo gasto para percorrer o percurso e de %.2fs.", tempo);


    return 0;
}