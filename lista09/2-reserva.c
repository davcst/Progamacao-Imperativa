#include <stdio.h>
#include <ctype.h>
#include <string.h>

int bbinaria(char *chave, int inicio, int fim, char vetor[][16]) {
    if (fim < inicio)
        return -1;
    else {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(vetor[meio], chave);
        
        if (comparacao == 0)
            return meio;
        else {
            if (comparacao < 0)
                return bbinaria(chave, meio + 1, fim, vetor);
            else
                return bbinaria(chave, inicio, meio - 1, vetor);
        }
    }
}

int main() {
    char nomes[15][16] = {"Ana", "Alice", "Bernardo", "Bruno", "Carlinhos", "Caique", "Davi", "Daniel", "Emanuel", "Eduardo", "Fernanda", "Felipe", "Geovana", "Geroncio", "Maju"};
    
    char chave[16];
    
    printf("Digite um nome: ");
    gets(chave);

    int indice = bbinaria(chave, 0, 15, nomes);

    if (indice != -1)
        printf("'%s' encontrado na posição %d.\n", chave, indice + 1);
    else
        printf("'%s' não encontrado.\n", chave);

    return 0;
}

