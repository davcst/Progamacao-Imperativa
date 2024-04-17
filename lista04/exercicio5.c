#include <stdio.h>

int main(){

    int pH;

    do{
        printf("Ph: ");
        scanf("%d", &pH);

        if(pH > 7)
            printf("BASICA\n");
        else if(pH < 7 && pH >= 0)
            printf("ACIDA\n");
        else if(pH == 7) 
            printf("NEUTRA\n");
        else if(pH != -1)
            printf("VALOR INVALIDO\n");

        char escolha;
        printf("Deseja continuar? (S/N)");
        scanf(" %c", &escolha);
        if(escolha == 'N' || escolha == 'n')
            return pH = -1;

    }while (pH != -1);

    return 0;
}