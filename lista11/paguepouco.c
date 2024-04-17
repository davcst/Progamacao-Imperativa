#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma{
	char Nome[21];
	float Preco;
	int QEstoque;
  int Status;
};
  
typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;
  
FILE *ArqFarma;

long int Tamanho=21*sizeof(char)+sizeof(float)+ 2 *sizeof(int);

int buscarFarmaco(char nome[]){
    fseek(ArqFarma, 0, 0);
    int encontrado = 0;
    int posicao = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma)){
      if (RgFarma.Status == 1 && strcmp(RgFarma.Nome, nome) == 0){
        encontrado = 1;
        break;
      }
      posicao++;
    }
    if (encontrado)
       return posicao;
    else
      return -1;
}

void Incluir() {
  char R, S;
  do{
    //system("cls");
    //ArqFarma = fopen("Farmacos.dat", "r+b");
    printf("*** inclusao ***\n\n");
    //fseek(ArqFarma, 0, 0);
    char nomeTemp[21];
    printf("Nome: ");
    scanf("%s", nomeTemp);
    int farmacoRep = 0;
    int posicaoFarmaco = buscarFarmaco(nomeTemp);

    if(posicaoFarmaco != -1)
      ArqFarma = fopen("Farmacos.dat", "r+b");
    else
      ArqFarma = fopen("Farmacos.dat", "a+b");

    do{
	    fread(&RgFarma, Tamanho, 1, ArqFarma);
	    if (strcmp(RgFarma.Nome, nomeTemp) == 0){
	      farmacoRep = 1;	
	      printf("\nO farmaco '%s' ja existe no arquivo.\n\n", RgFarma.Nome);
        }
    }while (!feof(ArqFarma) && (farmacoRep == 0) && (RgFarma.Status != 0));

    if(farmacoRep == 1 && (RgFarma.Status == 0)){
      
        printf("Deseja o reincluir ao estoque? ");
        scanf(" %c", &S);

        if(S == 'S' || S == 's'){
          printf("Estoque: ");
          scanf("%d",&RgFarma.QEstoque);
          RgFarma.Status = 1;
          fseek(ArqFarma, 0, 2);
          fwrite(&RgFarma, Tamanho, 1, ArqFarma);
          printf("\nFarmaco reincluido com sucesso!\n\n");
        }            
    }
    
    if(farmacoRep == 0){
      //ArqFarma = fopen("Farmacos.dat", "a+b");
      printf("Preco: ");
      scanf("%f",&RgFarma.Preco);
      printf("Estoque: ");
      scanf("%d",&RgFarma.QEstoque);
      strcpy(RgFarma.Nome, nomeTemp); 
      RgFarma.Status = 1;
      fseek(ArqFarma, 0, SEEK_END);
      fwrite(&RgFarma, Tamanho, 1, ArqFarma);
      printf("\nNovo farmaco incluido com sucesso!\n\n");
    }

    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
    fclose(ArqFarma);
  }while (R!='N');
  //fclose(ArqFarma);
  return;
}

void Excluir(){
char R, S;
fclose(ArqFarma);
ArqFarma = fopen("Farmacos.dat", "r+b");
 
  do{
    
    //system("cls");
    printf("*** exclusao ***\n\n");
    fseek(ArqFarma, 0, 0);
    char nomeTemp[21];
    printf("Nome: ");
    scanf("%s", nomeTemp);
    int farmacoExcluido = 0;
    //fread(&RgFarma, Tamanho, 1, ArqFarma);
	  
    while(fread(&RgFarma, Tamanho, 1, ArqFarma)){
	    if (RgFarma.Status == 1 && strcmp(RgFarma.Nome, nomeTemp) == 0){
        
        printf("Realmente deseja exluir o farmaco? (S/N)");
        scanf(" %c", &S);
        //getchar();
        S=toupper(S);
        farmacoExcluido = 1; 
          	
        if(S == 'S'){	                     
          RgFarma.Status = 0;
          fseek(ArqFarma, -Tamanho, SEEK_CUR);
          fwrite(&RgFarma, Tamanho, 1, ArqFarma);
          printf("Exclusao efetuada com sucesso!\n");
          farmacoExcluido = -1;           
        }  
        break;     
      }
    } 

    if(farmacoExcluido == 0)
        printf("Farmaco inexistente no estoque");

    printf("\nNova exclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
  }while (R!='N');
  fclose(ArqFarma);
  return;
}

long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/Tamanho;
	return R;
}
	
void Alterar(){
    if (TArquivo() != 0)
    {

      fclose(ArqFarma); // modo a + b
      ArqFarma = fopen("Farmacos.dat", "r+b");
      // system("cls");
      printf("* alterar *\n\n");
      fseek(ArqFarma, 0, 0);
      printf("Qual farmaco? ");
      char Farmaco[21];
      scanf("%s", Farmaco);
      int Achou = 0;
      do{
        fread(&RgFarma, Tamanho, 1, ArqFarma);
        if (strcmp(RgFarma.Nome, Farmaco) == 0){
          Achou = 1;
          printf("Nome: %s\n", RgFarma.Nome);
          printf("Valor: %.2f\n", RgFarma.Preco);
          printf("Estoque: %d\n", RgFarma.QEstoque);
        }
      } while (!feof(ArqFarma) && (Achou == 0) && (RgFarma.QEstoque >= 0));
      if (Achou == 0)
        printf("Registro inexistente!");
      else{
        printf("Qual o novo preco? \n");
        scanf("%f", &RgFarma.Preco);
        printf("Qual a nova quantidade? \n");
        scanf("%d", &RgFarma.QEstoque);
        fseek(ArqFarma, -Tamanho, 1);
        fwrite(&RgFarma, Tamanho, 1, ArqFarma);
          printf(">>> Alteracao efetuada com sucesso! <<<\n");
      }
      // system("pause");
      fclose(ArqFarma);
      ArqFarma = fopen("Farmacos.dat", "a+b");
    }
    else
      printf("Arquivo Vazio.  Nao existem dados a alterar.");
    fclose(ArqFarma);
    // system("pause");
    return;
}

void Consultar(){
  //system("cls");
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[21];
  scanf("%s",Farmaco);
  int Achou=0;
  do{
	  fread(&RgFarma,Tamanho,1,ArqFarma);
	  if (strcmp(RgFarma.Nome,Farmaco)==0){
	    Achou=1;	
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);
    }
  }while (!feof(ArqFarma) && (Achou == 0) && (RgFarma.QEstoque >= 0));
  if (Achou==0)
    printf("Registro inexistente!");  
  //system("pause");
  return;
}

void LTodos() {
  ArqFarma=fopen("Farmacos.dat","r+b");
  //system("cls");
  printf("*** lista todos ***\n\n"); 
  fseek(ArqFarma, 0, 0);
  while(fread(&RgFarma, Tamanho, 1, ArqFarma) == 1){
      //fread(&RgFarma, Tamanho, 1, ArqFarma);
      if (RgFarma.Status ==1){
        printf("Nome: %s\n", RgFarma.Nome);
        printf("Valor: R$%.2f\n", RgFarma.Preco);
        printf("Estoque: %d\n", RgFarma.QEstoque);
        printf("***\n\n");
      }
  }
  //system("pause");
  fclose(ArqFarma);
  return;
}


int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
	  //system("cls");
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break; 
      case 'E': Excluir(); break; 
      case 'A': Alterar(); break; 
      case 'C': Consultar(); break; 
      case 'T': LTodos(); break;}} 
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;
}
