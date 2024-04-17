#include <stdio.h>

int fatorial(int n) {

    int resultado = 1; 
    for (int i = 1; i <= n; i++){ 
        resultado *= i;
    }

    return resultado;
}

int main(){

    int n, Numero, Fatorial;
    printf("Digite a quantidade de numeros a serem calculados: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        
        printf("Digite o %d numero: ", i);
        scanf("%d", &Numero);

        Fatorial = fatorial(Numero);
        printf("%d! = %d\n", Numero, Fatorial);
        
    }

    return 0;
}