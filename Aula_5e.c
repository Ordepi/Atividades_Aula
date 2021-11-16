#include <stdio.h>
/* Calcula a divisão de A por B*/
int quociente(int A, int B) {
    if (B > A)
        return 0;
    else
        return(1 + quociente(A - B, B));
}
int main(void) {
    int A, B;

    do {
        printf("Digite um valor para A: ");
        scanf("%d", &A);
    } while (A < 0);
    do {
        printf("Digite um valor para B: ");
        scanf("%d", &B);
    } while (B <= 0);
    
    printf("O valor da divisao eh: %d", quociente(A, B));
    
    return 0;
}