#include <stdio.h>

int main()
{
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("Seu numero e: %d \n", numero);

    int numeroMen = numero - 1;
    printf("Seu numero subtraido de um e: %d \n", numeroMen);

    int numeroMa = numero + 1;
    printf("Seu numero adicionado de um e: %d \n", numeroMa);

    return 0;
}