#include <stdio.h>
// Programa que Calcula o Fatorial de N
int fat (int N) {
    if  (N == 0)
        return 1;
    else
        return (N * fat(N - 1));
}
int main (void) {
    int N;
   
    do {
        printf("Digite um numero natural: ");
        scanf("%d", &N);
    } while (N < 0);
    
    printf("O fatorial de %d eh: %d\n", N, fat(N));
    
    return 0;
}