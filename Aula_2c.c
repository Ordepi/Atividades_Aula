/*Faça um programa que leia 3 valores inteiros
(diferentes) e escreva qual o maior.*/
#include <stdio.h>

int main(void){
    int a, b, c;
    
    printf("Digite os tres numeros: \n");
    scanf("%d %d %d", &a, &b, &c);

    if((a > b) && (a > c))
       printf("O %d eh o maior numero", a);
    else
    	if(b > c)
           printf("O %d eh o maior numero", b);
    	else
           printf("O %d eh o maior numero", c);

    return 0;
}