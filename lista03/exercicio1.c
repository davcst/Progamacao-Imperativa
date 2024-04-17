int main(){
	
    int passageiros;
    printf("Digite o numero de passageiros: ");
    scanf("%d", &passageiros);

	int viagemKombi = passageiros / 11;
	int viagemColetivo = passageiros % 11;
	
	if(viagemKombi != 0 && viagemColetivo != 0)
		printf("Serao necessarias %d viagens de kombi e %d viagens de coletivo.", viagemKombi, viagemColetivo);
	else if(viagemKombi != 0 && viagemColetivo == 0)
		printf("Serao necessarias %d viagens de kombi.", viagemKombi);
	else if(viagemKombi == 0 && viagemColetivo != 0)
		printf("Serao necessarias %d viagens de coletivo.", viagemColetivo);
	else
		printf("Nao iremos ao museu");


    return 0;
}
