#include <stdio.h>

int main()
{
    int numero;
    printf("Digite um numero inteiro ");
    scanf("%d", &numero);

    int numero2 = numero * 2;
    int numero3 = numero * 3;
    int numero4 = numero * 4;
    int numero5 = numero * 5;
    int numero6 = numero * 6;
    int numero7 = numero * 7;
    int numero8 = numero * 8;
    int numero9 = numero * 9;
    int numero10 = numero * 10;

    printf(" %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n ",
    numero, numero2, numero3, numero4, numero5, numero6, numero7, numero8
    , numero9, numero10);


    return 0;
}