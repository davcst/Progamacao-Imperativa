#include <stdio.h>


int main(){

    int n1;
    printf("Digite um numero inteiro de 3 algarismos: ");
    scanf("%d", &n1);


    int inverso;
    inverso += n1 / 100;
    inverso += (n1 % 100) - (n1 % 10);
    inverso += (n1 % 10) * 100;
    
    printf("Numero lido = %d \nNumero Gerado = %d\n", n1, inverso);

    if(inverso > n1) 
     printf("NUMERO GERADO MAIOR QUE NUMERO LIDO"); 
    else if(inverso < n1) 
     printf("NUMERO GERADO MENOR QUE NUMERO LIDO"); 
    else  printf("NUMERO GERADO IGUAL AO NUMERO LIDO"); 


    return 0;
}