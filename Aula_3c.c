/* Faça um programa para calcule o fatorial de N. */
#include <stdio.h>

int main(void){

    int N, fat, memories;
    
    printf("Digite o numero ao qual deseja saber o fatorial: ");
    scanf("%d", &N);
    
    memories = N;
    
    for (fat = 1; N > 1; N--)
        fat *= N;
    
    printf("O fatorial de %d eh: %d", memories, fat);

    return 0;
}