#include <stdio.h>

int main()
{
    float comprimento;
    printf("Digite o comprimento do retangulo(cm): ");
    scanf("%f", &comprimento);

    float largura;
    printf("Digite o largura do retangulo(cm): ");
    scanf("%f", &largura);

    float area = comprimento * largura;
    printf("A area do retangulo e de %.3f cm.", area);


    return 0;
}