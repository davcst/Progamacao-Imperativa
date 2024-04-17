#include <stdio.h>

int foiAprovado(int p, int m, float r) {
  int minimoPortugues = 0.8 * 50;
  int minimoMatematica = 0.6 * 35;
  int minimoRedacao = 7;
  
  if (p >= minimoPortugues && m >= minimoMatematica && r >= minimoRedacao) {
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
    }
                  
    printf("%d\n", aprovados);

    return 0;
}   