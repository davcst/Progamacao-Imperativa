#include <stdio.h>

int lucro(int i){
    int f = i * 22;
    return f;
}

float media(float i){
    float f = i / 10;
    return f;
}

int main(){

    int Hora, NumPassageiros, MelhorHorario, TotalPassageiros, PiorHorario;
    int MaisPassageiros = 0;
    int MenosPassageiros = 999;

    for(Hora = 8; Hora <= 18; Hora++){
        printf("Numero de passgeiros das %d horas: ", Hora);
        scanf("%d", &NumPassageiros);
        if(NumPassageiros > MaisPassageiros){
            MelhorHorario = Hora;
            MaisPassageiros = NumPassageiros;
        }
        if(NumPassageiros < MenosPassageiros){
            PiorHorario = Hora;
            MenosPassageiros = NumPassageiros;
        }
        TotalPassageiros += NumPassageiros;
    }


    printf("Horario de maior procura: %d.\n", MelhorHorario);
    printf("Horario de menor procura: %d.\n", PiorHorario);
    printf("O total ganho no dia foi %d\n", lucro(TotalPassageiros));
    printf("O total de passageiros no dia foi %d\n", TotalPassageiros);
    printf("A media de passageiros no dia foi de %.1f\n", media(TotalPassageiros));


    return 0;
}
 