#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char S[21];
    printf("Escreva algo de ate 20 caracteres\n");
    gets(S);

    for(int i = 0; i < strlen(S); i++){
        S[i] = toupper(S[i]);
    }
    
    printf("%s", S);


    return 0;
}