#include <stdio.h>

int main() {
    int numero;

    printf("Digite um valor: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
      for (int j = 1; j <= i; j++) { 
        printf("%d ", j); 
      }
      printf("\n");
    }

    return 0;
}