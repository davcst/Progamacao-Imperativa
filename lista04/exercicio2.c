#include <stdio.h>

int main(){
	float Meta, Doacao, Soma = 0;
	printf("Meta da vaquinha: ");
	scanf("%f",&Meta);
    float MetaV = 0;

	do{
	  printf("Valor da doacao: ");
	  scanf("%f",&Doacao);
	  Soma = Soma + Doacao;
      printf("O valor recebido ate agora e de %.2f\n", Soma);
      }
	while (Soma<Meta); 

    float MetaUltrapassada = Soma - Meta;
	printf("A meta da vaquinha foi alcancada!\n");
    if(Soma > Meta)
        printf("A meta da vaquinha foi ultrapassada em %.2f reais", MetaUltrapassada);

    return 0;
}