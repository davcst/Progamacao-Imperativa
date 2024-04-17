#include <stdio.h>
#include <ctype.h>
#include <string.h>

int Nvogais(char P[21]){
    int nvogais = 0;
    for(int i = 0; i < strlen(P); i++){
        if( P[i] == 'a' || P[i] == 'A' || 
            P[i] == 'e' || P[i] == 'E' ||
            P[i] == 'i' || P[i] == 'I' || 
            P[i] == 'o' || P[i] == 'O' || 
            P[i] == 'u' || P[i] == 'U')
          nvogais++;
    }
    return nvogais;
}


int main(){

    char S[21];
    int n;
    printf("Quantas vezes quer realizar a operacao? \n");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        printf("Palavra: ");
        gets(S);
        printf("Numero de vogais: %d\n", Nvogais(S));
    }
       
    return 0;
}