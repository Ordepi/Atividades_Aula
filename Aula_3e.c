/* Fazer um programa que escreva a série de Fibonnacci, cujo último
termo seja menor ou igual a N. Obrigar o usuário a digitar um valor
positivo para N. */
#include <stdio.h>

int main(void){
    int N, soma, F1, F2;

    do{
        printf("Informe o numero parametro: ");
        scanf("%d", &N);
        if (N < 1)
            printf("Opcao Invalida");
    } while (N < 1);

    F1 = 0;
    F2 = 1;
    printf("\n\n%d %d", F1, F2);
    soma = F1 + F2;
    while (soma <= N){
        printf(" %d", soma);
        F1 = F2;
        F2 = soma;
        soma = F1 + F2;
    }

    return 0;
}