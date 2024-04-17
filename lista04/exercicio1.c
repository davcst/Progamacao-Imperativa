#include <stdio.h>

void ValidaCompra(float *L, float *C){

  float D;

  printf("\nCompra %.0f\n", *C);
  printf("Debito: ");
  scanf("%f",&D);

  if (*L - D >= 0){
	printf("Compra possivel! \n");
	*L -= D;
    *C += 1;}
  else
	printf("Esta compra \"estourara\" o cartao! \n");

  printf("Limite restante: %.2f \n\n",*L);}

int main(){
    float cont =1;
	float Limite;
	printf("Limite do cartao: ");
	scanf("%f",&Limite);


    while (Limite>0)
	    ValidaCompra(&Limite, &cont);
	printf("Seu limite de compras acabou!");
    return 0;
}