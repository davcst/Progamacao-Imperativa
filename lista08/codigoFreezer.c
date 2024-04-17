#include <stdio.h>
#include <stdlib.h>


float M[4][6]={{385,534,309,546,503,477},
        {12, 121, 12, 3, 24, 12},
        {35.9, 72.1, 46.2,74.3,78,90},
        {-28, -18, -18, -18, -22, -18}};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6], int L, int C){
  printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i = 0; i < L; i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) "); 
    for (int j=0; j<C; j++)
      printf("%6.1f",Matriz[i][j]);
    printf("\n");}};

void ExibeColuna(float Matriz[][6], int L, int C){
  for(int i = 0; i < L; i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) ");
    printf("%6.1f\n",Matriz[i][C]);}}

void ExibeLinha(float Matriz[][6],int L,int C){
  printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i = 0; i < C; i++)
    printf("%.1f ",Matriz[L][i]);
  printf("\n");}

void SelecionaFreezer(float Matriz[][6], int *F){
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
  *F=Op-1;};

void SelecionaCaracteristica(float Matriz[][6], int *C){
  system("cls");
  printf("Caracteristica desejado\n");
  printf("1 - Capacidade (litros)\n");
  printf("2 - Garantia (meses)\n");
  printf("3 - Economia(kWh/mes)\n");
  printf("4 - Temperatura Minima (Celsius)\n");
  printf("Opcao: ");
  int Op;
  scanf("%d", &Op);
  *C=Op-1;};

void AlterarMatriz(float Matriz[][6], int F, int C) {
    printf("Digite o novo valor: ");
    float novoValor;
    scanf("%f", &novoValor);
    Matriz[F][C] = novoValor;
    printf("\nValor alterado com sucesso!\n");
}

void MFcapacidade(float Matriz[][6], int L){
  int Mcapacidade = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[0][i] > Matriz[0][Mcapacidade]) {
          Mcapacidade = i;
        }
    }
  if(Mcapacidade == 0)
    printf("O melhor freezer em capacidade e Deia.\n");
  else if(Mcapacidade == 1)
    printf("O melhor freezer em capacidade e Sul.\n");
  else if(Mcapacidade == 2)
    printf("O melhor freezer em capacidade e NSul.\n");
  else if(Mcapacidade == 3)
    printf("O melhor freezer em capacidade e Frio.\n");
  else if(Mcapacidade == 4)
    printf("O melhor freezer em capacidade e Fri.\n");
  else if(Mcapacidade == 5)
    printf("O melhor freezer em capacidade e Lux.\n");
  printf("Capacidade: %.2f meses.\n", Matriz[2][Mcapacidade]);
}

void MFgarantia(float Matriz[][6], int L){
  int Mgarantia = 0;
    for (int i = 1; i < L; i++) {
        if (Matriz[1][i] > Matriz[1][Mgarantia]) {
          Mgarantia = i;
        }
    }
  if(Mgarantia == 0)
    printf("O melhor freezer em garantia e Deia.\n");
  else if(Mgarantia == 1)
    printf("O melhor freezer em garantia e Sul.\n");
  else if(Mgarantia == 2)
    printf("O melhor freezer em garantia e NSul.\n");
  else if(Mgarantia == 3)
    printf("O melhor freezer em garantia e Frio.\n");
  else if(Mgarantia == 4)
    printf("O melhor freezer em garantia e Fri.\n");
  else if(Mgarantia == 5)
    printf("O melhor freezer em garantia e Lux.\n");
  printf("Garantia: %.2f meses.\n", Matriz[2][Mgarantia]);
}

void MFeconomia(float Matriz[][6], int F){
  int Meconomia = 0;
    for (int i = 1; i < F; i++) {
        if (Matriz[2][i] < Matriz[2][Meconomia]) {
          Meconomia = i;
        }
    }

  if(Meconomia == 0)
    printf("O melhor freezer em economia e Deia.\n");
  else if(Meconomia == 1)
    printf("O melhor freezer economia e Sul.\n");
  else if(Meconomia == 2)
    printf("O melhor freezer em economia e NSul.\n");
  else if(Meconomia == 3)
    printf("O melhor freezer em economia e Frio.\n");
  else if(Meconomia == 4)
    printf("O melhor freezer em economia e Fri.\n");
  else if(Meconomia == 5)
    printf("O melhor freezer em economia e Lux.\n");
  printf("Gasto (Kwh/mes): %.2f.\n", Matriz[2][Meconomia]);
}

void MFtemperatura(float Matriz[][6], int F){
  int Meconomia = 0;
    for (int i = 1; i < F; i++) {
        if (Matriz[3][i] < Matriz[3][Meconomia]) {
          Meconomia = i;
        }
    }
  if(Meconomia == 0)
    printf("A menor temperatura e da marca Deia.\n");
  else if(Meconomia == 1)
    printf("A menor temperatura e da marca Sul.\n");
  else if(Meconomia == 2)
    printf("A menor temperatura e da marca NSul.\n");
  else if(Meconomia == 3)
    printf("A menor temperatura e da marca Frio.\n");
  else if(Meconomia == 4)
    printf("A menor temperatura e da marca Fri.\n");
  else if(Meconomia == 5)
    printf("A menor temperatura e da marca Lux.\n");
  
  printf("Temperatura minima: %.2f.\n)", Matriz[3][Meconomia]);
}
              
int main(){
  do{
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
    switch (Op){
      case 1: ExibeMatriz(M, 4, 6);
              system("pause");
              break;
      case 2: SelecionaFreezer(M, &Frz);
              ExibeColuna(M,4,Frz);
              system("pause");
              break;
      case 3: SelecionaCaracteristica(M, &Crc);
              ExibeLinha(M,Crc,6);
              system("pause");
              break;
      case 4: SelecionaFreezer(M, &Frz);
              SelecionaCaracteristica(M, &Crc);
              AlterarMatriz(M, Frz, Crc);
              system("pause");
              break; 
      case 5: MFcapacidade(M, 6);
              system("pause");
              break;
      case 6: MFgarantia(M, 6);
              system("pause");
              break;
      case 7: MFeconomia(M, 6);
              system("pause");
              break;
      case 8: MFtemperatura(M, 6);
              system("pause");
              break;
      case 9: break;}
      if (Op==9)
        break;}
  while (1);
  return 0;
}