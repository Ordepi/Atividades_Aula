/* Faça um programa que:
    * Crie uma fila encadeada com números inteiros
    * Os números devem ser inseridos na pilha até que o usuário digite um número negativo
    * Ao final do programa, imprima a fila
    * Devem ser criadas as funções insere e remove */
#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *prox;
};
typedef struct NO tyno;


void insereElem(tyno **inicio, tyno **fim, int elem){
    tyno *el;
    
    el = (tyno*) malloc(sizeof(tyno));
    el->info = elem;
    el->prox = NULL;
    
    if ((*inicio) == NULL)
        (*inicio) = el;
    else
        (*fim)->prox = el;
    (*fim) = el;
}
tyno *removeElem(tyno *inicio){
    tyno *lixo;
    
    if (inicio != NULL) {
        lixo = inicio;
        inicio = inicio->prox;
        free(lixo);
    }
    
    return inicio;
}
int main(void) {
    tyno *inicio, *fim;
    int num;
    
    inicio = NULL;
    fim = NULL;
    printf("Digite um num: ");
    scanf("%d", &num);
    while (num >=0) {
        insereElem(&inicio,&fim,num);
        printf("Digite um num: ");
        scanf("%d", &num);
    }
    printf("\nFila -> ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->info);
        inicio = removeElem(inicio);
    }
    
    return 0;
}