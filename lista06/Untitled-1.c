#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    for(int i = 1; i <= 101; i++){
        char M[11], Am[5], Cm[3];
        printf("Digite a matricula do aluno %d  ", i);
        gets(M);

        M[6] = '\0';
        strcpy(Cm, &M[4]);
        M[4] = '\0';
        strcpy(Am, &M[0]);

        if(strcmp(Cm,"97") == 0)
            printf("Matricula %d:\n  Ano: %s\n  Curso: agroecologia\n", i, Am);
        if(strcmp(Cm,"99") == 0)
            printf("Matricula %d:\n  Ano: %s\n  Curso: gerontologia\n", i, Am);
        else
            printf("Matricula %d:\n  Ano: %s\n  Curso: XXXX\n", i, Am);
        

    }

    return 0;
}