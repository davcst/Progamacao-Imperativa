#include <stdio.h>
#include <ctype.h>


int numeroD(int a, int b){
    int saida = 1;

    for(int i = 0; i < b; i++){
        saida *= 10; 
    }

 return (a / saida) % 10;
}


int main(){

    int numero;
    printf("Digite um numero de 5 algarismos: ");
    scanf(" %d", &numero);



    char selecao;


    do{
        
     printf("Escolha uma casa para destacar \n");
     printf("U – Unidade\n");
     printf("D - Dezena \n");
     printf("C - Centena \n");
     printf("M - Milhar \n");
     printf("Z - Dezena de Milhar \n");
     printf("S - Sair do programa\n");
     scanf(" %c", &selecao);
     selecao=toupper(selecao);

     switch(selecao){
        case 'U': printf("Unidade = %d.\n", numeroD(numero, 0)); 
         break;
        case 'D': printf("Dezena %d\n", numeroD(numero, 1)); 
         break;
        case 'C': printf("Centena: %d\n", numeroD(numero, 2)); 
         break;
        case 'M': printf("Milhar: %d\n", numeroD(numero, 3)); 
         break;
        case 'Z': printf("Dezena de Milhar: %d\n", numeroD(numero, 4)); 
         break;
        case 'S': printf("Saindo do programa");
         break;
        default: printf("Opcao invalida, digite novamente.\n");    
     }
    }while(selecao != 'S');

    return 0;
}
