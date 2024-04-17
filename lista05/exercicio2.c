#include <stdio.h>

float parcelamentoV(float i){
    if(i > 300){
        for(int p = 1; p <= 10; p++){
            float parcelaV = (i / p) * 1.1;
            float juros = (i / p) * 0.1;
            float total = (i * 0.1 * p) + i;
            printf("Pagamento em %d mes - JUROS: R$%.2f - Total: %.2f - Parcela %dx R$%.2f\n", p, juros, total, p, parcelaV);
        } 
    }
    else
        printf("Nao e possivel parcelar essa compra");

    return 0;
}

int main(){

    float ValorCompra;
    printf("Qual o valor da compra? ");
    scanf("%f", &ValorCompra);
    //float parcelaValores = parcelamentoV(ValorCompra);

    char Escolha;
    printf("Deseja parcelar a compra? (S/N)");
    scanf(" %c", &Escolha);
    if(Escolha == 'S' || Escolha == 's')
        printf("%.0f", parcelamentoV(ValorCompra));
    else
        printf("Ok, obrigado pela compra!"); 


    return 0;
}