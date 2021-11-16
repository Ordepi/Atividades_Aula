#include <stdio.h>
/*Crie uma matriz N x N que representará as amizades entre um grupo de pessoas. 
A matriz AMIZADE é preenchida, em cada posição com o número 0 ou 1. O número 1 em uma posição i,j
indica que a pessoa i é amiga de j. Por outro lado, o número 0 indica que i e j não são amigos.
    o Faça um programa que preencha a matriz de amizades e depois verifique se existe alguma inconsistência, 
      já que a relação de amizade é recíproca.
    o Faça uma função que retorne quantas inconsistências existem na matriz.*/
#define N 4

void preencheMatriz(int mat[N][N]) {
    printf("\n\nPreenchendo a Matriz\n");
    
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            printf("Digite a posicao [%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
}
void escreve(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}
int confereamizade(int mat[N][N]) {
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (mat[j][i] != mat[i][j])
                count++;

    return count;
}
int main(void) {
    int mat[N][N];
    
    preencheMatriz(mat);
    printf("\n\nA matriz amizade eh:\n\n");
    escreve(mat);
    
    printf("Foram encontrados %d inconsistencias", confereamizade(mat));

    return 0;
}