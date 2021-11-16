#include <stdio.h>
//Calcula o produto dos numeros impares menores que num, com num incluido
int produto (int N) {
    if  (N == 1)
        return 1;
    else
        return (produto(N-2) * N);
}

int main (void) {
    int num;
    
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    } while (num <= 0);
    
    if (num % 2 == 0)
        num--;
    printf("O produto eh: %d", produto(num));
    
    return 0;
}