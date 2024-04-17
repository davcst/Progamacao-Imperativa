#include <stdio.h>
#include <math.h>

float NCubico(float A){
	
	float exponencial = pow(A, 3);
	
    return exponencial;
}

int main(){

	float numero, NumeroCubo;

	printf("N = ");
	scanf("%f", &numero);

	NumeroCubo = NCubico(numero);
	printf(" %.2f^3 = %.2f.",numero, NumeroCubo);


return 0;
}