/* Considere a estrutura ponto
    struct tipoPonto {
        int x;
        int y;
    };
Faça um programa que leia 2 pontos e implemente uma única função que:
    Receba os pontos lidos como parâmetros
    Retorne a multiplicação dos pontos
    Retorne a soma dos pontos */
#include <stdio.h>

struct tipoPonto {
    int x;
    int y;
};
typedef struct tipoPonto typonto;

void soma_mult(typonto P1, typonto P2, typonto *s, typonto *m) {
    s->x = P1.x + P2.x;
    s->y = P1.y + P2.y;
    m->x = P1.x * P2.x;
    m->y = P1.y * P2.y;
}
int main(void) {
    typonto ponto1, ponto2, soma, mult;
    
    printf("\nDigite as coordenadas do ponto1:\n");
    scanf("%d %d", &ponto1.x, &ponto1.y);
    printf("\nDigite as coordenadas do ponto2:\n");
    scanf("%d %d", &ponto2.x, &ponto2.y);

    soma_mult(ponto1,ponto2,&soma,&mult);
    
    printf("\nA soma dos pontos: (%d,%d)", soma.x,soma.y);
    printf("\nA mult dos pontos: (%d,%d)", mult.x,mult.y);
    
    return 0;
}