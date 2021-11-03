/* Fazer um programa que leia N números naturais e que escreva o
somatório dos números pares e a média dos múltiplos de 3. */
#include <stdio.h>

int main(void) {

    int N, soma2 = 0, soma3 = 0, cont3 = 0, num;
    
    do{
        printf("Digite o numero de numeros: ");
        scanf("%d", &N);
    } while (N < 1);
    
    for (int i = 1; i <= N; i++){
        printf("Digite um numero: ");
        scanf("%d", &num);
        
        if (num % 2 == 0)
            soma2 += num;
        if (num % 3 == 0){
            soma3 += num;
            cont3++;
        }
    }
    
    printf("\nA soma dos numeros pares eh: %d", soma2);
    
    if (cont3 > 0)
        printf("\nA media dos multiplos de 3 eh: %.2f", soma3/(1.0*cont3));
    else
        printf("\nNao eh possivel calcular a media, pois nao hah numeros multiplos de 3");

    return 0;
}