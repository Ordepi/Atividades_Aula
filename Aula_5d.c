#include <stdio.h>
// escreve os números pares menores do que N
void escrevePar(int num) {
    if (num != 0) {
        escrevePar (num - 2);
        printf(" %d", num);
    }
}
int main(void) {
    int num;

    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    } while (num <= 0);
    
    printf("Os numeors pares menores do que %d sao: \n", num);

    if (num % 2 != 0)
        num--;
    escrevePar (num);

    return 0;
}