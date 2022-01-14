/* Faça um programa que:
    * Crie uma pilha encadeada com números inteiros
    * Os números devem ser inseridos na pilha até que o usuário digite um número negativo
    * Ao final do programa, imprima a pilha
    * Devem ser criadas as funções push e pop */
#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *prox;
};
typedef struct NO tyno;


tyno *push (tyno *topo, int elem) {
    
    tyno *el;
    
    el = (tyno*) malloc(sizeof(tyno));
    el->info = elem;
    el->prox = topo;
    topo = el;
    
    return topo;
}
tyno *pop (tyno *topo) {
    
    tyno *lixo;
    
    if (topo != NULL) {
        lixo = topo;
        topo = topo->prox;
        free(lixo);
    }
    
    return topo;
}
int main (void) {
    
    tyno *topo;
    int num;
    
    topo = NULL;
    printf("Digite um num: ");
    scanf("%d", &num);
    while (num >=0) {
        topo = push(topo,num);
        printf("Digite um num: ");
        scanf("%d", &num);
    }
    printf("\nPilha -> ");
    while (topo != NULL) {
        printf("%d -> ", topo->info);
        topo = pop(topo);
    }
    
    return 0;
}