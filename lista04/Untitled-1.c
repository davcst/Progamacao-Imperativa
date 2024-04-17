#include <stdio.h>

int main(){

    float nota1, nota2, nota3;
    char continuar = 'S';

  while(continuar == 'S' || continuar == 's'){
  
    printf("Digite as suas 3 notas: ");
    scanf("%f%f%f", &nota1, &nota2, &nota3);

    float media = (nota1 + nota2 + nota3) / 3;

    if(media >= 7 && media <= 10)
        printf("Parabens, voce foi APROVADO.\nSua media e de %.2f", media);
    else if(media > 3 && media < 7)
        printf("Voce esta em RECUPERACAO.\nSua media e de %.2f", media);
    else if(media <= 3 && media >= 0)
        printf("Voce foi REPROVADO.\nSua media e de %.2f", media);
    else
        printf("ERRO - Valores invalidos.");

    printf("Deseja continuar? (S/N)");
    scanf(" %c", &continuar);

  }


    return 0;
}