#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RegMoto{
    char Nome[20];
    char Modelo[10];
    char Placa[7];
    char Defeito[50];
    char Mecanico[20];
    char Status;
    float Preco;
};

typedef struct RegMoto TpRegMoto;
TpRegMoto VZonda[50];

struct TpHistorico {
    char Data[11];
    float Caixa;
};

typedef struct TpHistorico TpHISTORICO;
TpHISTORICO RgHistorico;

FILE *ArqMoto;
long int Tamanho = sizeof(TpRegMoto);

FILE *ArqHistorico;
long int TamanhoH = sizeof(TpHISTORICO);

int Quant = -1; // Controla o preenchimento do vetor
float Soma = 0;

long int TArquivo(){
    fseek(ArqMoto, 0, 2);
    long int R = ftell(ArqMoto) / Tamanho;
    return R;
}

long int TArquivoH(){
    fseek(ArqHistorico, 0, 2);
    long int R = ftell(ArqHistorico) / TamanhoH;
    return R;
}

void IncluirDiaAnterior(){
    if (TArquivo() != 0){
        fseek(ArqMoto, 0, 0);
        for (int i = 0; !feof(ArqMoto); i++) { 
            if (fread(&VZonda[i].Nome, Tamanho, 1, ArqMoto) != 1)
                break; 
            Quant = Quant + 1;
        }
        fclose(ArqMoto);
        ArqMoto = fopen("Motos.dat", "w+b");
    }
}

void AtualizarHistorico(){
    printf("Insira a data: ");
    scanf(" %s", RgHistorico.Data);
    RgHistorico.Caixa = Soma;

    fseek(ArqHistorico, 0, 2);
    fwrite(&RgHistorico, TamanhoH, 1, ArqHistorico);
}

void SolicitaServico(){
    char Sair = 'S';
    do {
        if (Quant < 50) {
            printf("\n\n >>> Motos Zonda <<< \n\n");
            Quant = Quant + 1;
            printf("Qual o nome do cliente? ");
            scanf(" %[^\n]s", VZonda[Quant].Nome);
            printf("Qual o modelo da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Modelo);
            printf("Qual a placa da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Placa);
            printf("Qual o defeito da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Defeito);
            strcpy(VZonda[Quant].Mecanico, "NAO DEFINIDO");
            VZonda[Quant].Status = '0';
            VZonda[Quant].Preco = 0;
            printf("\n\n Deseja inserir novo servico? S|N ");
            scanf(" %c", &Sair);
            Sair = toupper(Sair);
        } else {
            printf("Limite de solicitações atingido.\n");
            break;
        }
    } while (Sair != 'N');
}

void IniciaServico(){
    char P[7];
    printf("Placa da moto para iniciar servico: ");
    scanf(" %[^\n]s", P);
    int Pos = -1; // posição da moto P no vetor

    for (int i = 0; i <= Quant; i++)
        if (strcmp(VZonda[i].Placa, P) == 0)
            Pos = i;
    if (Pos == -1)
        printf("Moto nao cadastrada!");
    else{
        char M[20];
        printf("Nome do mecanico: ");
        scanf(" %[^\n]s", M);
        strcpy(VZonda[Pos].Mecanico, M);

        printf("\n\n Cliente %d: %s", Pos + 1, VZonda[Pos].Nome);
        printf("\n Modelo: %s", VZonda[Pos].Modelo);
        printf("\n Placa: %s", VZonda[Pos].Placa);
        printf("\n Defeito: %s", VZonda[Pos].Defeito);

        VZonda[Pos].Status = '1';
        printf("\n Status: %c", VZonda[Pos].Status);
        printf("\n Mecanico: %s", VZonda[Pos].Mecanico);

        if (VZonda[Pos].Preco == 0)
            printf("\n Preco: NAO DEFINIDO");
        else
            printf("\n Preco: %.2f", VZonda[Pos].Preco);
    }
}

void RemoverSolicitacao(){
    char P[7];
    printf("Placa da moto para cancelar serviço: ");
    scanf(" %[^\n]s", P);
    int Pos = -1; // posição da moto P no vetor
    // busca da moto para iniciar serviço
    for (int i = 0; i <= Quant; i++)
        if (strcmp(VZonda[i].Placa, P) == 0)
            Pos = i;
    if (Pos == -1)
        printf("Moto nao cadastrada!");
    else{
        if(VZonda[Pos].Status == '0'){
            printf("\n Cliente %d: %s", Pos + 1, VZonda[Pos].Nome);
            printf("\n Modelo: %s", VZonda[Pos].Modelo);
            printf("\n Placa: %s", VZonda[Pos].Placa);
            printf("\n Defeito: %s", VZonda[Pos].Defeito);
            VZonda[Pos].Status = '2';
            printf("\n Status: %c", VZonda[Pos].Status);
            printf("\n Mecanico: %s", VZonda[Pos].Mecanico);
            printf("\n Preco: NAO DEFINIDO");
        }
        else{
            if(VZonda[Pos].Status == '1')
                printf("Nao e possivel realizar esta acao, mecanico ja iniciou o servico!");
            if(VZonda[Pos].Status == '3')
                printf("Nao e possivel realizar esta acao, serviço ja foi finalizado!");  
        }
    }
}

void ConsultarSolicitacoes(){
    printf("\n\n >>> Motos Zonda <<< \n\n");
    if (Quant == -1)
        printf("Nao ha servicos cadastrados.");
    else{
        for (int i = 0; i <= Quant; i++){
            printf("\n Cliente %d: %s", i + 1, VZonda[i].Nome);
            printf("\n Modelo: %s", VZonda[i].Modelo);
            printf("\n Placa: %s", VZonda[i].Placa);
            printf("\n Defeito: %s", VZonda[i].Defeito);
            printf("\n Status: %c", VZonda[i].Status);
            printf("\n Mecanico: %s", VZonda[i].Mecanico);
            if (VZonda[i].Preco == 0)
                printf("\n Preco: NAO DEFINIDO");
            else
                printf("\n Preco: %.2f", VZonda[i].Preco);
            printf("\n --------------------- \n\n");
        }
    }
}

void ConcluirServico(){
    char P[7];
    printf("Placa da moto para iniciar servico: ");
    scanf(" %[^\n]s", P);
    int Pos = -1; // posição da moto P no vetor
    // busca da moto para iniciar serviço
    for (int i = 0; i <= Quant; i++)
        if (strcmp(VZonda[i].Placa, P) == 0)
            Pos = i;
    
    if (Pos == -1)
        printf("Moto nao cadastrada!");
    else{
        if(VZonda[Pos].Status == '2')
            printf("Servico cancelado, nao e possivel concluir servico.");
        else {
            if(VZonda[Pos].Status == '0')
                printf("Servico nao iniciado, nao e possivel concluir servico.");
            else{
                printf("Preco do servico: ");
                float Precccco;
                scanf(" %f", &Precccco);
                VZonda[Pos].Preco = Precccco;

                printf("\n Cliente %d: %s", Pos + 1, VZonda[Pos].Nome);
                printf("\n Modelo: %s", VZonda[Pos].Modelo);
                printf("\n Placa: %s", VZonda[Pos].Placa);
                printf("\n Defeito: %s", VZonda[Pos].Defeito);
                VZonda[Pos].Status = '3';
                printf("\n Status: %c", VZonda[Pos].Status);
                printf("\n Mecanico: %s", VZonda[Pos].Mecanico);
                printf("\n Preco: %.2f", VZonda[Pos].Preco);
            }
        }
    }
}

void QuantidadeServicos(){
    int cadastrado = 0;
    int concluido = 0;
    int andamento = 0;
    int rejeitado = 0;

    for(int i = 0; i<=Quant; i++){
        if(VZonda[i].Status == '0')
            cadastrado = cadastrado+1;
        if(VZonda[i].Status == '1')
            andamento = andamento+1;
        if(VZonda[i].Status == '2')
            rejeitado = rejeitado+1;
        if(VZonda[i].Status == '3')
            concluido = concluido+1;
    }
    printf("Servicos cadastrados: %d\n", cadastrado);
    printf("Servicos em andamento: %d\n", andamento);
    printf("Servicos rejeirados: %d\n", rejeitado);
    printf("Servicos concluidos: %d\n", concluido); 
}

void EncerrarExpediente(){
    printf("\n\n>>>>>> Servicos do dia <<<<<<\n");
    
    ConsultarSolicitacoes();

    QuantidadeServicos();
    
    printf("\n\n>>>>>> Saldo <<<<<<\n");
    for(int i=0; i<=Quant; i++){
        Soma = Soma + VZonda[i].Preco;
    }
    printf("Valor em caixa: %.2f \n", Soma);

    printf("\n\n >>> Motos Para Amanha <<< \n\n");
    for (int i = 0; i <= Quant; i++){
        if((VZonda[i].Status == '0') || (VZonda[i].Status == '1')){
            printf("\n Cliente %d: %s", i + 1, VZonda[i].Nome);
            printf("\n Modelo: %s", VZonda[i].Modelo);
            printf("\n Placa: %s", VZonda[i].Placa);
            printf("\n Defeito: %s", VZonda[i].Defeito);
            printf("\n Status: %c", VZonda[i].Status);
            printf("\n Mecanico: %s", VZonda[i].Mecanico);
            printf("\n Preco: NAO DEFINIDO");
            printf("\n --------------------- \n\n");

            fseek(ArqMoto, 0, 2);
            fwrite(&VZonda[i], Tamanho, 1, ArqMoto);
        }
    }
AtualizarHistorico();
}

void HistoricoFinanceiro(){
    if (TArquivoH() != 0){
        float Total = 0;
        float MaiorValor = 0;
        char MaiorData[11];
        //system("cls");
        printf("* Dados Financeiros *\n\n");
        fseek(ArqHistorico, 0, 0);
        do{
            if (fread(&RgHistorico, TamanhoH, 1, ArqHistorico) != 1) // Verifica se a leitura foi bem-sucedida
                break; // Sai do loop se a leitura falhar
            printf("Data: %s\n", RgHistorico.Data);
            printf("Caixa: %.2f\n\n", RgHistorico.Caixa);

            Total = Total + RgHistorico.Caixa;

            if (RgHistorico.Caixa > MaiorValor){
              MaiorValor = RgHistorico.Caixa;
              strcpy(MaiorData, RgHistorico.Data);
            }
        } while (!feof(ArqHistorico));

        printf("_______\n\n");
        printf("Total: %.2f\n\n", Total);

        printf("Melhor Data: %s\n", MaiorData);
        printf("Melhor Caixa: %.2f\n", MaiorValor);
        
    } else {
        printf("Arquivo Vazio. Nao existem dados a listar.\n");
    }
}

int main(){
    ArqMoto = fopen("Motos.dat", "a+b");
    ArqHistorico = fopen("Historico.dat", "a+b");

    IncluirDiaAnterior();
    
    //system("cls"); // limpa tela
    int Opcao;
    do {
        // Exibicao de menu e leitura da opcao.
        printf("\n\n >>> Motos Zonda <<< \n\n");
        printf("1 - Solicitar Servico \n");
        printf("2 - Iniciar Servico \n");
        printf("3 - Remover Solicitacao \n");
        printf("4 - Consultar Solicitacoes \n");
        printf("5 - Concluir Servico \n");
        printf("6 - Encerrar Expediente \n");
        printf("7 - Historico Financeiro \n");
        printf("8 - Sair \n\n");
        printf("Digite a opcao desejada: ");
        scanf(" %d", &Opcao);
        switch (Opcao){
            case 1: SolicitaServico(); break;
            case 2: IniciaServico(); break;
            case 3: RemoverSolicitacao(); break;
            case 4: ConsultarSolicitacoes(); break;
            case 5: ConcluirServico(); break;
            case 6: EncerrarExpediente(); break; //Opcao = 8;
            case 7: HistoricoFinanceiro(); break;
            case 8: break;
            default:
                printf("Insira uma opcao valida!\n");
                //system("pause");
        }
    } while (Opcao != 8);
    fclose(ArqMoto);
    fclose(ArqHistorico);
    return 0;
}