#include <stdio.h>
#include <ctype.h>
#include <string.h>


int Fmatricula(char M[11]){

    char Cm[3], Am[5];
    
    M[6] = '\0';
    strcpy(Cm, &M[4]);
    M[4] = '\0';
    strcpy(Am, &M[0]);

    if(strcmp(Cm, "97") == 0)
        printf("Dados Matricula:\n  Ano: %s\n  Curso: agroecologia\n", Am);
    else if(strcmp(Cm, "99") == 0)
        printf("Dados Matricula:\n  Ano: %s\n  Curso: gerontologia\n", Am);
    else
        printf("Dados Matricula:\n  Ano: %s\n  Curso: XXXX\n", Am);

    return 0;
}


int main(){

    char M[11];
    for(int i = 1; i < 101; i++){
        printf("Digite a matricula do aluno %d:  ", i);
        gets(M);
        Fmatricula(M);
    }

    return 0;
}