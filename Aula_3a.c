/* Faça um programa para somar os múltiplos de N menores do que 200. */
#include <stdio.h>

int main(void){
    
    int N, i, soma = 0;
    printf("Digite um numero: ");
    scanf("%d", &N);

    while (i < 200){
        i = N;
        if (i % N == 0)
            soma += i;
        i++;
    }
    
    printf("A soma dos multiplos de %d menores do que 200 eh: %d", N, soma);
    
    return 0;
}