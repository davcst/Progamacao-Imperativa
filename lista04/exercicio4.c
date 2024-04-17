#include <stdio.h>

int main(){

    const int Dmes = 30;
    int dias, meses = 0;

    printf("Digite a quantidade de dias ");
    scanf("%d", &  dias);
    int diasF = dias;
    
    while(diasF >= Dmes){
        meses++;
        diasF -= Dmes;
    }

    printf("%d dias e equivalente a %d meses.", dias, meses);



    return 0;
}