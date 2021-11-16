#include <stdio.h>
// Programa que Calcula X elevado a N, sendo N >= 0
int pot(int X, int N) {
    if (N == 0)
        return 1;
    else
        return(pot(X, N - 1) * X);
}
int main(void) {

    int N, X;

    printf("Digite o numero: ");
    scanf("%d", &X);
    
    do {
        printf("Digite a potencia: ");
        scanf("%d", &N);
    } while (N <= 0);
    
    printf("%d elevado a %d corresponde ah: %d", X, N, pot(X, N));

    return 0;
}