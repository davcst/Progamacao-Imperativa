#include <stdio.h>

int main()
{
    int ano;
    printf("Qual o ano da primeira dose? ");
    scanf("%d", &ano);

    int doses;
    printf("Qual o intervalo entre as doses? ");
    scanf("%d", &doses);

    int dose2 = ano + doses;
    int dose3 = doses + dose2;
    int dose4 = doses + dose3;

    printf("Anos das demais doses: %d, %d, %d", dose2, dose3, dose4);

    return 0;
}