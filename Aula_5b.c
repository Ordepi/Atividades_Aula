#include <stdio.h>
/* Calcula a soma dos números inteiros entre A e B, inclusive */
int soma_ent(int A, int B) {
    if (B == A)
        return B;
    else
        return(soma_ent(A, B - 1) + B);
}
int main(void) {

    int A, B;

    do {
        printf("Diigite um valor para A: ");
        scanf("%d", &A);
    } while (A < 0);
    do {
        printf("Digite um valor para B: ");
        scanf("%d", &B);
    } while (B <= A);
    
    printf("A soma dos numeros entre %d e %d eh: %d", A, B, soma_ent(A, B));

    return 0;
}