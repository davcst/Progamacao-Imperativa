#include <stdio.h>

int main(){

    int N;
    printf("Digite um dividendo: ");
    scanf("%d", &N);

    int A, B;
    printf("Digite dois divisores: ");
    scanf("%d %d", &A, &B);  

    if(N % A == 0 && N % B != 0)
        printf("ATENDE A CONDICAO");
    else if(N % A != 0 && N % B == 0)
        printf("ATENDE A CONDICAO");
    else
        printf("NAO ATENDE A CONDICAO");

    //O problema poderia ser resolvido ao contrario tambem

    // if(N % A == 0 && N % B == 0)
    //     printf("NAO ATENDE A CONDICAO");
    // else 
    //     printf("ATENDE A CONDICAO");

    return 0;
}



