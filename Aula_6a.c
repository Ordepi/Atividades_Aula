#include <stdio.h>
/* Ler 20 números inteiros e depois imprimí-los na ordem contrária em que foram lidos.*/
#define TAM  20

int main (void) {
    int vetor[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("Digite um valor para a %dº posicao do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    printf("\n\n");

    for (int j = TAM - 1; j >= 0; j--) {
        printf(" %d", vetor[j]);
    }

    return 0;
}