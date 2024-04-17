#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct TurmaAprendaProgramacao{
    char nome[21], Sfinal[21];
    float notas[3], frequencia, media;
}Aluno;

int main(){

    Aluno alunos[80];
    float SomaMedia = 0;
    const float frequencia = 65;
    float MediaGeral;
    
    printf("TURMA APRENDA PROGRAMACAO\n\nDigite os dados dos alunos:\n");
    for(int i = 0; i < 80; i++){
        printf("Aluno %d: \n", i+1);
        printf(" Nome: ");
        gets(alunos[i].nome);

        printf(" Nota 1: ");
        scanf("%f", &alunos[i].notas[0]);
        printf(" Nota 2: ");
        scanf("%f", &alunos[i].notas[1]);
        printf(" Nota 3: ");
        scanf("%f", &alunos[i].notas[2]);

        printf(" Frequencia em porcentagem: ");
        scanf("%f", &alunos[i].frequencia);
        getchar();

        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        SomaMedia += alunos[i].media;
    }

    MediaGeral = SomaMedia / 80;

    printf("Resultados: \n\n");
    printf("Media geral da turma: %.2f\n", MediaGeral);

    for(int i = 0; i < 80; i++){
        printf(" Aluno: %s\n", alunos[i].nome);
        printf(" Notas: %.2f %.2f %.2f\n", alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2]);
        printf(" Média: %.2f\n", alunos[i].media);
        printf(" Frequência: %.2f%%\n", alunos[i].frequencia);
        if(alunos[i].media >= MediaGeral && alunos[i].frequencia >= frequencia)
            printf(" Situação: APROVADO\n\n");
        else
            printf(" Situação: REPROVADO\n\n");
    }

    return 0;
}