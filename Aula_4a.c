/* Faça um programa que leia N valores em dólar e que transforme para real. Deve ser feita uma função que receba o
valor em dólar, a cotação e retorne o equivalente em real. */
#include <stdio.h>

float dolar_real(float a, float b){
    return(a * b);
}

int main(void) {
    float dolar, cotacao;
    printf("Informe a cotacao atual: ");
    scanf("%f", &cotacao);
    printf("\n\n============================================================================================================\n\n");
    printf("                       Para parar o programa digite zero, ou um numero inferior a zero                              ");
    printf("\n\n============================================================================================================\n\n");
    printf("Digite um valor em dolar $");
    scanf("%f", &dolar);
    do
    {
        printf("\n$%.2f dolares hoje equivalem hah R$%.2f\n\n", dolar, dolar_real(dolar, cotacao));
        printf("Digite um valor em dolar $");
        scanf("%f", &dolar);
    } while (dolar > 0);

    return 0;
}