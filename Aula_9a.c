/* Faça um programa que crie uma fila com os N números de processos que estão esperando para executar em um sistema;
Considere que os X (X < N) primeiros processos terminaram a sua execução;
Escreva o nome do primeiro processo da Fila;
Implemente a estrutura de Fila e as funções para inserir e remover elementos; */
#include <stdio.h>

#define MAX 20

struct FILA {
    int dado[MAX];
    int inicio, fim, total;
};
typedef struct FILA tyfil;

void insert(tyfil *F, int num) {
    if (F->total < MAX) {
        F->dado[F->fim] = num;
        F->fim++;
        F->fim = F->fim%MAX;
        F->total++;
    }
}
int remover(tyfil *F) {
    int num;
    if (F->total > 0) {
        num = F->dado[F->inicio];
        F->inicio++;
        F->inicio = F->inicio%MAX;
        F->total--;
    }
    return num;
}
int main(void) {

    tyfil F;
    int proc, N, X, i;
    
    F.total=0;
    F.fim=0;
    F.inicio=0;
    
    printf("Digite a quantidade de processos: ");
    scanf("%d", &N);
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("Digite o num do processo que quer executar: ");
        scanf("%d", &proc);
        insert(&F,proc);
    }
    
    printf("\nDigite a quantidade de processos que executou: ");
    scanf("%d", &X);
    
    printf("\n\nEXECUTANDO processos...\n");
    for (i = 0; i < X; i++)
        printf("\n[%d]",remover(&F));
    
    printf("\n\nO proximo eh: %d", F.dado[F.inicio]);
    
    return 0;
}