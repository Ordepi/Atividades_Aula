#include <stdio.h>
/*Faça um programa que preencha uma matriz NxN e que escreva a soma dos elementos da diagonal principal.
    a. Faça uma função para preencher a matriz;
    b. Faça uma função que escreva a matriz formatada;
    c. Faça uma função que retorne a soma dos elementos da diagonal principal.*/
#define N 3

void preencheMatriz(int mat[N][N]) {
    printf("\nPreenchendo a Matriz\n");
    
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            printf("Digite a posicao [%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
}
void escreve(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        printf("[ ");
        for (int j = 0; j < N; j++) 
            printf("%d ",mat[i][j]);
        printf("]\n");
    }
}
int somaDiagonalPrincipal(int mat[N][N]) {    
    int soma = 0;
    
    for (int i = 0; i < N; i++) 
        soma = soma + mat[i][i];
    
    return soma;
}
int main(void) {    
    int mat[N][N], soma;
    
    preencheMatriz(mat);
    printf("\nA matriz:\n\n");
    escreve(mat);
    
    soma = somaDiagonalPrincipal(mat);
    printf("\nA soma da diagonal principal eh: %d", soma);
       
    return 0;
}