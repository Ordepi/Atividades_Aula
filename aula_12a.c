/* Considere duas listas encadeadas L1 e L2, onde cada nó da lista possui duas partes: dado e prox. 
Para cada item abaixo, faça uma função que receba as duas listas como parâmetros e as concatene de acordo com as características especificadas.
Para concatenar L1 com L2 basta juntar o final de L1 com o começo de L2, formando uma única lista com endereço inicial em L1.
a) L1 e L2 são simplesmente encadeadas, não circulares e sem nós cabeça.
b) L1 e L2 são simplesmente encadeadas, circulares e sem nós cabeça à NÃO.
c) L1 e L2 são simplesmente encadeadas, circulares e com nós cabeça.
d) L1 e L2 são simplesmente encadeadas, não circulares e com nós cabeça.
e) L1 e L2 são duplamente encadeadas, circulares e com nós cabeça. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO {
    char dado[10];
    struct NO *prox;
};
typedef struct NO tyno;

int buscaElem(tyno *L, char *fruta, tyno **pre){
    tyno *aux, *preL;
    aux = L;
    preL= NULL;
    while ((aux != NULL) && (strcmp(fruta,aux->dado) > 0)) {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux != NULL) && (strcmp(fruta,aux->dado) == 0))
        return 1;
    return 0;
}
tyno *insereElem(tyno *L, char *fruta) {
    tyno *pre, *el;
    if (!buscaElem(L,fruta,&pre)) {
        el = (tyno *)malloc(sizeof(tyno));
        strcpy(el->dado,fruta);
        if (L == NULL || pre == NULL) {
            el->prox = L;
            L = el;
        } else {
            el->prox = pre->prox;
            pre->prox = el;
        }
    } else
        printf("--> Elemento jah existe\n");
    return L;
}
void imprimeLista(tyno *L) {
    while (L != NULL) {
        printf("%s -> ", L->dado);
        L = L->prox;
    }
}
tyno* concatena(tyno *L1, tyno *L2){
    tyno *aux1, *aux2;
    
    if (L2 != NULL) {
        if (L1 != NULL) {
            aux1 = L1;
            while (aux1->prox != NULL)
                aux1 = aux1->prox;
            aux1->prox = L2;
        } else
            L1 = L2;
    }
    
    return L1;
}
int main(void) {
    tyno *L1, *L2;
    char fruta[10];
    int op;
    
    L1 = NULL;
    printf("\n------ CRIANDO L1 ------\n");
    printf("Digite uma fruta: ");
    scanf(" %s", fruta);
    while (strcmp(fruta,"fim") != 0) {
        L1 = insereElem(L1,fruta);
        printf("Digite uma fruta: ");
        scanf("%s", fruta);
    }
    
    L2 = NULL;
    printf("\n------ CRIANDO L2 ------\n");
    printf("Digite uma fruta: ");
    scanf(" %s", fruta);
    while (strcmp(fruta,"fim") != 0) {
        L2 = insereElem(L2,fruta);
        printf("Digite uma fruta: ");
        scanf("%s", fruta);
    }
    
    printf("\n\n L1 -> ");
    imprimeLista(L1);
    printf("\n\n L2 -> ");
    imprimeLista(L2);
    
    L1 = concatena(L1,L2);
    printf("\n\n(L1+L2) -> ");
    imprimeLista(L1);
    return 0;
}