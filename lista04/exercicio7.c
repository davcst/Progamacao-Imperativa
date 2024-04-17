#include <stdio.h>

int foiAprovado(int p, int m, float r) {
  int minPortugues = 0.8 * 50;
  int minMatematica = 0.6 * 35;
  int minRedacao = 7;
  
  if (p >= minPortugues && m >= minMatematica && r >= minRedacao) {
    return 1;
  }
  
  return 0;
}

int main() {
    int aprovados = 0;

    while (1) {
        int p, m;
        float r;
        scanf("%d", &p);
        
        if (p < 0) {
          break;
        }
        
        scanf("%d", &m);
        scanf("%f", &r);
  
        if (foiAprovado(p, m, r)) {
          aprovados++;
        }

        char escolha;
        printf("Deseja continuar? (S/N)");
        scanf(" %c", &escolha);
        if(escolha == 'N' || escolha == 'n')
            return 0;
    }
                  
    printf("%d\n", aprovados);

    return 0;
}