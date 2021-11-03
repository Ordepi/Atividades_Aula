/* Faça um programa que calcule o valor de E.
E = 1 + 1/(1!) + 1/(2!) + 1/(3!) + ... + 1/(N!) */
#include <stdio.h>

int main(void){

    int N, fat = 1;
    float E = 1;
    
    printf("Digite o numero ao qual deseja utilizar para melhor aproximacao do valor de E: ");
    scanf("%d", &N);
        
    for (int i = 1; i <= N; i++){
        fat *= i;
        E += (1.0 / fat); 
    }
    printf("O fatorial de E eh: %f", E);

    return 0;
}