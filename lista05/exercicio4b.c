#include <stdio.h>

int main(){

    int Aluno, Avaliacao;
    float Nota; 
    float NotaM = 0;

    for(Aluno = 1; Aluno < 51; Aluno++){

        for(Avaliacao = 1; Avaliacao < 13; Avaliacao++){
            printf("Aluno %d digite o valor da avaliacao %d: ", Aluno, Avaliacao);
            scanf("%f", &Nota);
          
            if(Nota >= 7)
                NotaM++;
            if(NotaM == 5){
                printf("Aluno %d esta aprovado\n", Aluno);
                NotaM = 0;
                break;
            }
            if(NotaM < 5 && Avaliacao == 12)
                printf("Aluno %d esta reprovado\n", Aluno);
        }
    }

    return 0;
}