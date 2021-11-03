/*Faça um programa que leia a base e altura de um triângulo e que escreva a sua área*/
#include <stdio.h>

int main(void){
    
    float b, h;

    printf("Digite a base triangulo: \n");
    scanf("%f", &b);
    printf("Digite a altura triangulo: \n");
    scanf("%f", &h);
    printf("A area do triangulo eh: %.2f", (b*h)/2);
    
    return 0;
}