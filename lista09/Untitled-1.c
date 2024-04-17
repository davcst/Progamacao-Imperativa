#include <stdio.h>
#include <stdlib.h>

struct Tpfreezer {
    char nome[5];
    float capacidade;
    int garantia;
    float economia;
    float temperatura;
};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6], int L, int C) {
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        for (int j = 0; j < C; j++)
            printf("%6.1f", Matriz[i][j]);
        printf("\n");
    }
}

void ExibeColuna(float Matriz[][6], int L, int C) {
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        printf("%6.1f\n", Matriz[i][C]);
    }
}

void ExibeLinha(float Matriz[][6], int L, int C) {
    printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < C; i++)
        printf("%.1f ", Matriz[L][i]);
    printf("\n");
}

void SelecionaFreezer(float Matriz[][6], int *F) {
    printf("Selecione o freezer desejado:\n");
    printf("1 - Deia\n");
    printf("2 - Sul\n");
    printf("3 - NSul\n");
    printf("4 - Frio\n");
    printf("5 - Fri\n");
    printf("6 - Lux\n\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *F = Op - 1;
}

void SelecionaCaracteristica(float Matriz[][6], int *C) {
    system("cls");
    printf("Caracteristica desejado\n");
    printf("1 - Capacidade (litros)\n");
    printf("2 - Garantia (meses)\n");
    printf("3 - Economia(kWh/mes)\n");
    printf("4 - Temperatura Minima (Celsius)\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *C = Op - 1;
}

void AlterarMatriz(float Matriz[][6], int F, int C) {
    printf("Digite o novo valor: ");
    float novoValor;
    scanf("%f", &novoValor);
    Matriz[F][C] = novoValor;
    printf("\nValor alterado com sucesso!\n");
}

void MFcapacidade(struct Tpfreezer Matriz[], int L) {
    int Mcapacidade = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[i].capacidade > Matriz[Mcapacidade].capacidade) {
            Mcapacidade = i;
        }
    }
    printf("O melhor freezer em capacidade e %s.\n", Matriz[Mcapacidade].nome);
    printf("Capacidade: %.2f litros.\n", Matriz[Mcapacidade].capacidade);
}

void MFgarantia(struct Tpfreezer Matriz[], int L) {
    int Mgarantia = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[i].garantia > Matriz[Mgarantia].garantia) {
            Mgarantia = i;
        }
    }
    printf("O melhor freezer em garantia e %s.\n", Matriz[Mgarantia].nome);
    printf("Garantia: %d meses.\n", Matriz[Mgarantia].garantia);
}

void MFeconomia(struct Tpfreezer Matriz[], int L) {
    int Meconomia = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[i].economia < Matriz[Meconomia].economia) {
            Meconomia = i;
        }
    }
    printf("O melhor freezer em economia e %s.\n", Matriz[Meconomia].nome);
    printf("Gasto (Kwh/mes): %.2f.\n", Matriz[Meconomia].economia);
}

void MFtemperatura(struct Tpfreezer Matriz[], int L) {
    int Mtemperatura = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[i].temperatura < Matriz[Mtemperatura].temperatura) {
            Mtemperatura = i;
        }
    }
    printf("O menor temperatura e da marca %s.\n", Matriz[Mtemperatura].nome);
    printf("Temperatura minima: %.2f.\n", Matriz[Mtemperatura].temperatura);
}


int main() {
    struct Tpfreezer M[6] = {
        {"Deia", 385, 12, 35.9, -28},
        {"Sul", 534, 121, 72.1, -18},
        {"NSul", 309, 12, 46.2, -18},
        {"Frio", 546, 3, 74.3, -18},
        {"Fri", 503, 24, 78, -22},
        {"Lux", 477, 12, 90, -18}
    };

    do {
        system("cls");
        printf(">>> Pesquisa Freezer <<<\n\n");
        printf("Selecione a opcao desejada:\n");
        printf("1 - Exibir Levantamento\n");
        printf("2 - Dados de um Freezer\n");
        printf("3 - Dados de uma Caracteristica\n");
        printf("4 - Alterar Dado\n");
        printf("5 - Melhor Freezer em Capacidade\n");
        printf("6 - Melhor Freezer em Garantia\n");
        printf("7 - Melhor Freezer em Economia\n");
        printf("8 - Melhor Freezer em Temperatura\n");
        printf("9 - Sair\n");
        int Op;
        scanf("%d", &Op);
        switch (Op) {
            case 1:
                ExibeMatriz(M, 4, 6);
                system("pause");
                break;
            case 2:
                SelecionaFreezer(M, &Frz);
                ExibeColuna(M, 4, Frz);
                system("pause");
                break;
            case 3:
                SelecionaCaracteristica(M, &Crc);
                ExibeLinha(M, Crc, 6);
                system("pause");
                break;
            case 4:
                SelecionaFreezer(M, &Frz);
                SelecionaCaracteristica(M, &Crc);
                AlterarMatriz(M, Frz, Crc);
                system("pause");
                break;
            case 5:
                MFcapacidade(M, 6);
                system("pause");
                break;
            case 6:
                MFgarantia(M, 6);
                system("pause");
                break;
            case 7:
                MFeconomia(M, 6);
                system("pause");
                break;
            case 8:
                MFtemperatura(M, 6);
                system("pause");
                break;
            case 9:
                break;
        }
        if (Op == 9)
            break;
    } while (1);
    return 0;
}
