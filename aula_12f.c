/* Considere uma lista L simplesmente encadeada, com nó cabeça, que guarde nome de frutas. 
Cada nó da lista possui três partes: info, proxF e proxT.
    * info: guardará o nome da fruta.
    * proxF: guardará o ponteiro para o próximo no da lista L.
    * proxT: guardará o ponteiro para o início de uma outra lista, que armazenará os tipos da fruta.
A lista de tipos, será simplesmente encadeada e sem no cabeça. Cada nó possuirá duas partes: info e proxT.
    * info: guardará o tipo da fruta.
    * proxT: guardará o ponteiro para o próximo nó da lista de tipos de frutas.
Você deverá implementar uma lista de lista!
Crie uma lista L de frutas e seus tipos.
Primeiro insira nomes de frutas na lista L até que seja digitado a palavra fim.
Depois crie o seguinte MENU:
            1 – Insere fruta
            2 – Insere tipo da fruta
            3 – Remove elemento
            4 – Remove tipo da fruta
            5 – Mostra lista
            6 – Fim do programa
Crie funçoes para inserir fruta, inserir tipo, remover fruta, remover tipo, mostrar lista, buscar fruta, buscar tipo e para escrever o MENU. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO_tipo {
  char info[10];
  struct NO_tipo *proxT;
};
typedef struct NO_tipo tyntp;

struct NO_fruta {
  char info[10];
  struct NO_tipo *proxT;
  struct NO_fruta *proxF;
};
typedef struct NO_fruta tynfrt;

int menu() {
    int op;    
    printf("\n\nEscolha uma operacao: \n");
    printf("1: Insere Fruta\n");
    printf("2: Insere Tipo de Fruta\n");
    printf("3: Remove Fruta\n");
    printf("4: Remove Tipo de Fruta\n");
    printf("5: Mostra lista\n");
    printf("6: FIM\n");
    printf("==> ");
    scanf("%d", &op);
    return op;
}
int buscaFruta(tynfrt *L, char *fruta, tynfrt **pre) {
    tynfrt *aux, *preL;
    aux = L->proxF;
    preL= L;
    while ((aux != NULL) && (strcmp(fruta,aux->info) > 0)) {
        preL = aux;
        aux = aux->proxF;
    }
    (*pre) = preL;
    if ((aux != NULL) && (strcmp(fruta,aux->info) == 0))
        return 1;
    return 0;
}
int buscaTipo(tyntp *T, char *tipoFruta, tyntp **pre) {
    tyntp *aux, *preT;
    aux = T;
    preT = NULL;
    while ((aux != NULL) && (strcmp(tipoFruta,aux->info) > 0)) {
        preT = aux;
        aux = aux->proxT;
    }
    (*pre) = preT;
    if ((aux != NULL) && (strcmp(tipoFruta,aux->info) == 0))
        return 1;
    return 0;
}
void insereFruta(tynfrt *L, char *fruta) {
  tynfrt *pre, *el;
  if (!buscaFruta(L, fruta, &pre)) {
    el = (tynfrt *)malloc(sizeof(tynfrt));
    strcpy(el->info,fruta);
    el->proxT = NULL;
    el->proxF = pre->proxF;
    pre->proxF = el;
  } else
        printf("--> Fruta ja cadastrada\n");
}
void insereTipoFruta(tynfrt *L, char *fruta, char *tipoFruta) {
  tynfrt *preF, *auxF;
  tyntp *preT, *auxT, *elTipo;

  if (buscaFruta(L, fruta, &preF)) {
    auxF = preF->proxF;
    auxT = auxF->proxT;
    if (!buscaTipo(auxT, tipoFruta, &preT)) {
      elTipo = (tyntp *)malloc(sizeof(tyntp));
      strcpy(elTipo->info,tipoFruta);
      if (preT == NULL) {
        elTipo->proxT = auxF->proxT;
        auxF->proxT = elTipo;
      } else {
        elTipo->proxT = preT->proxT;
        preT->proxT = elTipo;
      }
    } else
        printf("\n--> Tipo de fruta jah cadastrado\n");
  } else
        printf("\n--> Nao eh possivel incluir este tipo, pois a Fruta nao esta cadastrada\n");
}
void removeFruta(tynfrt *L, char *fruta) {
    tynfrt *pre, *lixo;
    tyntp *aux;

    if (buscaFruta(L,fruta,&pre)) {
        lixo = pre->proxF;
        pre->proxF = lixo->proxF;
        while (lixo->proxT != NULL) {
          aux = lixo->proxT;
          lixo->proxT = aux->proxT; 
          free(aux);
        }
        free(lixo);
    } else
        printf("\nFruta %s nao cadastrada\n", fruta);
}
void removeTipoFruta(tynfrt *L, char *fruta, char *tipoFruta) {
  tynfrt *preF, *auxF;
  tyntp *preT, *auxT, *lixoTipo;

    if (buscaFruta(L,fruta,&preF)) {
        auxF = preF->proxF;
        auxT = auxF->proxT;
        if (buscaTipo(auxT,tipoFruta,&preT)) {
        if (preT == NULL) {
            lixoTipo = auxT;
            auxF->proxT = lixoTipo->proxT;
        } else {
            lixoTipo = preT->proxT;
            preT->proxT = lixoTipo->proxT; 
        }
        free(lixoTipo);
        } else
            printf("\n--> Tipo de fruta nao cadastrado\n");
    } else
        printf("\n--> Nao eh possivel apagar este tipo, pois a Fruta nao esta cadastrada\n");
}
void imprimeLista(tynfrt *L) {
  tyntp *auxT;
  
    if (L != NULL) {
        printf("\n%10s: ", L->info);
        auxT = L->proxT;
        while (auxT != NULL) {
          printf(" -> %s ", auxT->info);
          auxT = auxT->proxT; 
        }
        imprimeLista(L->proxF);
    }
}
int main(void) {
    tynfrt *L;
    char fruta[10], tipoFruta[10];
    int op;
    
    L = (tynfrt *) malloc(sizeof(tynfrt));
    L->proxF = NULL;
    L->proxT = NULL;
    printf("Digite uma fruta: ");
    scanf(" %s", fruta);
    while (strcmp(fruta,"fim") != 0) {
      insereFruta(L,fruta);
      printf("Digite uma fruta: ");
      scanf("%s", fruta);
    }
    do {
        op = menu();
        switch (op) {
            case 1:
                printf("\nDigite o nome da fruta para inserir: ");
                scanf(" %s", fruta);
                insereFruta(L,fruta);
                break;
            case 2:
                printf("\nPrimeiro, digite o nome da fruta: ");
                scanf(" %s", fruta);
                printf("\nAgora, digite o tipo da fruta para inserir: ");
                scanf(" %s", tipoFruta);
                insereTipoFruta(L,fruta, tipoFruta);
                break;
            case 3:
                printf("\nEscolha uma fruta para remover: ");
                scanf(" %s", fruta);
                removeFruta(L,fruta);
                break;
            case 4:
                printf("\nPrimeiro, digite o nome da fruta: ");
                scanf(" %s", fruta);
                printf("\nAgora, digite o tipo da fruta para remover: ");
                scanf(" %s", tipoFruta);
                removeTipoFruta(L,fruta, tipoFruta);
                break;
            case 5:
                printf("\nLISTA DE FRUTAS \n ");
                imprimeLista(L->proxF);
                break;
            case 6:
                printf("\nFim do programa\n");
                break;
            default:
                printf("\nOpcao Invalida!\n");
        }
    } while (op != 6);
    return 0;
}