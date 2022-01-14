/* Crie 2 listas L1 e L2 (com nós cabeça) de números inteiros que representarão conjuntos matemáticos. 
As listas devem ser preenchidas até que o usuário digite um número negativo.
Não podem possuir números repetidos.
Os conjuntos não precisam estar ordenados.
Devem ser criadas as funções insereElem e buscaElem.
A função insereElem não deve incluir os elementos ordenadamente, podem ser inseridos sempre no inicio.
Crie o seguinte MENU para o usuário e implemente funções para cada item:
    1 – Mostra L1 e L2
    2 – Interseção de L1 e L2 
    3 – União de L1 e L2
    4 – Fim do programa */
#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *prox;
};
typedef struct NO tynokb;

int menu() {
    int op;
    
    printf("\n\nEscolha uma operacao: \n");
    printf("1: Mostra L1 e L2\n");
    printf("2: Intersecao de L1 e L2\n");
    printf("3: Uniao de L1 e L2\n");
    printf("4: FIM\n");
    printf("==> ");
    scanf("%d", &op);
    
    return op;
}
int buscaElem (tynokb *L, int numero, tynokb **pre){
    tynokb *aux, *preL;
    aux = L->prox;
    preL= L;
    while ((aux != NULL) && (numero > aux->info)) {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux != NULL) && (numero == aux->info))
        return 1;
    return 0;
}
void insereElem (tynokb *L, int num) {
    tynokb *pre, *el;
    if (!buscaElem(L,num,&pre)) {
        el = (tynokb *)malloc(sizeof(tynokb));
        el->info = num;
        el->prox = pre->prox;
        pre->prox = el;
    } else
        printf("--> Elemento jah existe\n");
}
void intersecao(tynokb *L1, tynokb *L2) {
    tynokb *aux;
    
    L1 = L1->prox;
    while (L1 != NULL) {
        aux = L2->prox;
        while (aux != NULL) {
            if (L1->info == aux->info) {
                printf(" %d ->",aux->info);
                break;
            }
            aux = aux->prox;
        }
        L1 = L1->prox;
    }
}
void uniao(tynokb *L1, tynokb *L2) {
    tynokb *aux;
    int aux2;
    
    L1 = L1->prox;
    while (L1 != NULL) {
        aux = L2->prox;
        aux2 = 0;
        while (aux != NULL) {
            if (L1->info == aux->info) {
                aux2 = 1; 
                break;
            } else
                aux = aux->prox;
        }
        if (!aux2)
            printf(" %d ->",L1->info);
        L1 = L1->prox;
    }
    
    aux = L2->prox;
    while (aux != NULL) {
          printf(" %d ->",aux->info);
          aux = aux->prox;
    }
}
void imprimeLista (tynokb *L) {
    if (L != NULL) {
        printf("%d -> ", L->info);
        imprimeLista(L->prox);
    }
}
int main (void) {
    tynokb *L1, *L2;
    int num, op;
    
    L1 = (tynokb *) malloc(sizeof(tynokb));
    L1->prox = NULL;
    L2 = (tynokb *) malloc(sizeof(tynokb));
    L2->prox = NULL;
    printf("\n\nCriando L1\n");
    printf("Digite um numero: ");
    scanf("%d", &num);
    while (num >= 0) {
        insereElem(L1,num);
        printf("Digite um numero: ");
        scanf("%d", &num);
    }
    printf("\n\nCriando L2\n");
    printf("Digite um numero: ");
    scanf("%d", &num);
    while (num >= 0) {
        insereElem(L2,num);
        printf("Digite um numero: ");
        scanf("%d", &num);
    }
    do {
        op = menu();
        switch (op) {
            case 1:
                printf("\nL1 -> ");
                imprimeLista(L1->prox);
                printf("\nL2 -> ");
                imprimeLista(L2->prox);
                break;
            case 2:
                printf("\nLI -> ");
                intersecao(L1, L2);
                break;
            case 3:
                printf("\nLU -> ");
                uniao(L1, L2);
                break;
            case 4:
                printf("\nFim do programa\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 4);
    return 0;
}