#include <stdio.h>
/* Faça um programa que preencha uma matriz 3x4 com números inteiros.
    a. Faça uma função para preencher a matriz;
    b. Faça uma função que escreva a matriz formatada; */
#define L 3
#define C 4

void escreve (int vet[L][C]) {
    printf("\n\n======================================================================================\n\n");
    for (int i = 0; i < L; i++) {
        printf("[");
        for (int j = 0; j < C; j++)
            printf("%4d", vet[i][j]);
        printf("]\n");
    }
    printf("\n======================================================================================");
}
void preenche_mat (int vet[L][C]) {
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++) {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &vet[i][j]);
        }
}
int main (void) {
    int matrix[L][C];
    
    preenche_mat(matrix);
    escreve(matrix);

    return 0;
}