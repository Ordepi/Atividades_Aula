/* Faça um programa que:
    * Crie uma lista encadeada L com nomes de frutas;
    * Os nomes devem ser inseridos na lista em ordem crescente até que o usuário digite a palavra ‘fim’;
    * A lista não deve possuir nomes repetidos;
    * Ao final do programa, imprima a lista;
    * Faça funções para inserir um elemento e imprimir a lista; 
Continue no programa anterior:
    * Após preencher a lista crie um MENU com as opções:

        1 – Insere elemento
        2 – Remove elemento
        3 – Mostra lista
        4 – Informa a quantidade de nós
        5 – Fim do programa

    * Além das funções já criadas, crie funções para remover um elemento, apresentar o menu na tela e uma função recursiva para contar os nós da lista*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO {
    char info[10];
    struct NO *prox;
};
typedef struct NO tynokb;

int menu() {
    int op;
    
    printf("\n\nEscolha uma operacao: \n");
    printf("1: Insere\n");
    printf("2: Remove\n");
    printf("3: Mostra\n");
    printf("4: Conta elementos\n");
    printf("5: FIM\n");
    printf("==> ");
    scanf("%d", &op);
    return op;
}
int buscaElem (tynokb *L, char *fruta, tynokb **pre){
    tynokb *aux, *preL;
    aux = L->prox;
    preL= L;
    while ((aux != NULL) && (strcmp(fruta,aux->info) > 0)) {
        preL = aux;
        aux = aux->prox;
    }
    (*pre) = preL;
    if ((aux != NULL) && (strcmp(fruta,aux->info) == 0))
        return 1;
    return 0;
}
void insereElem (tynokb *L, char *fruta) {
    tynokb *pre, *el;
    if (!buscaElem(L,fruta,&pre)) {
        el = (tynokb *)malloc(sizeof(tynokb));
        strcpy(el->info,fruta);
        el->prox = pre->prox;
        pre->prox = el;
    } else
        printf("--> Elemento jah existe\n");
}
void removeElem (tynokb *L, char *fruta) {
    tynokb *pre, *lixo;
    if (buscaElem(L,fruta,&pre)) {
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    } else
        printf("\nElemento %s nao existe\n", fruta);
}
void imprimeLista (tynokb *L) {
    
    if (L != NULL) {
        printf("%s -> ", L->info);
        imprimeLista(L->prox);
    }
    
}
int contaNo (tynokb *L) {
    
    if (L != NULL)
        return(contaNo(L->prox) + 1);
    else
        return 0;
    
}
int main (void) {
    tynokb *L;
    char fruta[10];
    int op;
    
    L = (tynokb *) malloc(sizeof(tynokb));
    L->prox = NULL;
    printf("Digite uma fruta: ");
    scanf(" %s", fruta);
    while (strcmp(fruta,"fim") != 0) {
        insereElem(L,fruta);
        printf("Digite uma fruta: ");
        scanf("%s", fruta);
    }
    do {
        op = menu();
        switch (op) {
            case 1:
                printf("\nDigite um elemento para inserir: ");
                scanf("%s", fruta);
                insereElem(L,fruta);
                break;
            case 2:
                printf("\nEscolha um elemento para remover: ");
                scanf("%s", fruta);
                removeElem(L,fruta);
                break;
            case 3:
                printf("\nLista -> ");
                imprimeLista(L->prox);
                break;
            case 4:
                printf("\nA lista possui %d elementos", contaNo(L->prox));
                break;
            case 5:
                printf("\nFim do programa\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 5);
    return 0;
}