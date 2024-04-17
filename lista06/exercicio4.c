#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
//diminuir a letra
    char escolha;
    do{
        char S[51], Nome[26], Sobrenome[26];
        int Tn, Ts, i;
        printf("Escreva seu primeiro nome e seu ultimo sobrenome\n");
        gets(S);

        for(i=0; i < strlen(S); i++){
            if(S[i] == ' '){
                Tn = i;
                break;
            }
        }
    
        S[0] = toupper(S[0]);
    
        for(int f = i + 1; f < strlen(S); f++){
            S[f] = toupper(S[f]);
        }

        Ts = i+1;

        strcpy(Nome, &S);
        Nome[i] = '\0';
        strcpy(Sobrenome, &S[Ts]);
        printf("%s, %s\n", Sobrenome, Nome);

        printf("Deseja continuar? (S/N)");
        scanf(" %c", &escolha);

        S[0] = '\0';
        Nome[0] = '\0';
        Sobrenome[0] = '\0';
        getchar();

    }while(escolha != 'n' && escolha != 'N');
    

    return 0;
}