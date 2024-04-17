#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char S[21];
    printf("Digite algo\n");
    gets(S);
    for(int i = 0; i < strlen(S); i++){
        S[i] = tolower(S[i]);
    }
    S[0] = toupper(S[0]);
    printf("%s", S);


    return 0;
}