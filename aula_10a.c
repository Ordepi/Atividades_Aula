/* Faça um programa que:
    * Crie uma lista encadeada L com números inteiros
    * Os números devem ser inseridos na lista em ordem crescente até que o usuário digite um número negativo.
    * A lista não deve possuir números repetidos
    * Ao final do programa, imprima a lista
    * Devem ser criadas as funções de buscaElemento, insereElemento e ImprimeLista */
#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *prox;
};
typedef struct NO tyno;

int buscaElem (tyno *L, int elem, tyno **pre) {
    tyno *aux, *preL;
    aux = L;
    preL= NULL;
    while ((aux != NULL) && (elem > aux->info)) {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux != NULL) && (elem == aux->info))
        return 1;
    return 0;
}
tyno *insereElem (tyno *L, int elem) {
    tyno *pre, *el;
    if (!buscaElem(L,elem,&pre)) {
        el = (tyno *)malloc(sizeof(tyno));
        el->info = elem;
        if (L == NULL || pre == NULL) {
            el->prox = L;
            L = el;
        } else {
            el->prox = pre->prox;
            pre->prox = el;
        }
    } else
        printf("--> Elemento já existe\n");
    return L;
}
tyno *removeElem (tyno *L, int elem) {
    tyno *pre, *lixo;
    if (buscaElem(L,elem,&pre)) {
        if (L->info == elem) {
            lixo = L;
            L = L->prox;
        } else {
            lixo = pre->prox;
            pre->prox = lixo->prox;
        }
        free(lixo);
    } else
        printf("\nElemento %d não existe\n", elem);
    return L;
}
void imprimeLista (tyno *L) {
    tyno *aux;
    
    aux = L;
    while (aux != NULL) {
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    
}
int main (void) {
    tyno *L;
    int num;
    
    L = NULL;
    printf("Digite um num: ");
    scanf("%d", &num);
    while (num >=0) {
        L = insereElem(L,num);
        printf("Digite um num: ");
        scanf("%d", &num);
    }
    printf("\n\nLista -> ");
    imprimeLista(L);
    
    printf("\n\nEscolha um elemento para remover: ");
    scanf("%d", &num);
    removeElem(L,num);
    printf("\n\nLista -> ");
    imprimeLista(L);
    
    return 0;
}