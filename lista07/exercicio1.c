#include <stdio.h>

int main() {
    int Vendas[300];
    int TotalVendas = 0;
    float MediaVendas;
    int AbaixoMedia = 0;

    printf("Digite o total de vendas de cada vendedor:\n");
    for (int i = 0; i < 300; i++) {
        printf("Vendedor %d: ", i + 1);
        scanf("%d", &Vendas[i]);
        TotalVendas += Vendas[i];
    }

    MediaVendas = TotalVendas / 300;
    for (int i = 0; i < 300; i++) {
        if (Vendas[i] < MediaVendas) {
            AbaixoMedia++;
        }
    }

    printf("A média de vendas do grupo de vendedores é: %.2f\n", MediaVendas);
    printf("O número de vendedores com vendas abaixo da média é: %d\n", AbaixoMedia);

    return 0;
}
