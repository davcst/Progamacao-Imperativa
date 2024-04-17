#include <stdio.h>

int main(){

    int mesV;
    float pesoInicial, pesoFinal;
    printf("Digite seu peso atual: ");
    scanf(" %f", &pesoInicial);
    printf("Digite o peso que deseja alcancar: ");
    scanf(" %f", &pesoFinal);

    //int pesoCalc = pesoFinal % 5;


    if(pesoInicial > pesoFinal){
        for(int mes = 1; pesoFinal < pesoInicial; mes++){
            pesoInicial -= 5;
            printf("%d mes = peso %.1f\n", mes, pesoInicial);   
            mesV = mes;
        }
        printf("Voce alcancara o peso %.1f em %d meses.\n", pesoInicial, mesV);
    }

    else
        printf("ERRO - Digite valores validos!");
        
    return 0;
}