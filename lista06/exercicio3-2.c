#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char escolha;
    do{
        char S[21], P;
        printf("Digite algo de ate 20 caracteres\n");
        gets(S);
        printf("Qual vogal deseja selecionar? \n");
        scanf(" %c", &P);

       int pos = 0;

        for (int i = 0; i < strlen(S); i++){
            if (S[i] == P){
                pos++;
            }
        }

        if (pos == 0)
            printf("Nao ha ocorrencia de %c em %s.\n", P, S);
        else
         printf("Existem %d ocorrencias de %c em %s.\n", pos, P, S);

        printf("Deseja continuar? (S/n) \n");
        scanf(" %c", &escolha);
        
    }while(escolha != 'n' && escolha != 'N');
    
    return 0;
}