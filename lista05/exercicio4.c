#include <stdio.h>

int main(){

    int Aluno, Avaliacao;
    float Nota; 
    float NotaM = 0;

    for(Avaliacao = 1; Avaliacao < 13; Avaliacao++){
        printf("Digite o valor da avaliacao %d: ", Avaliacao);
        scanf("%f", &Nota);

        if(Nota >= 7)
            NotaM += Nota;
    }

    if(NotaM >= 35)
        printf("Voce esta aprovado");
    else
        printf("Voce esta reprovado");

    return 0;
}