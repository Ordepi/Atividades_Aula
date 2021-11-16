#include <stdio.h>
/* Programa que informa o N-ésimo termo da série de Fibonacci */
int fib(int N) {
    if (N == 1)
        return 0;
    else 
        if (N == 2)
            return 1;
        else
            return (fib(N-2) + fib(N-1));
}
int main(void) {
    int N;

    do {
        printf("Digite a posicao do numero na serie de Fibonacci, que deseja saber: ");
        scanf("%d", &N);
    } while (N < 1);
    
    printf("O %d° termo da serie fibonacci eh o elemento: %d", N, fib(N));

    return 0;
}