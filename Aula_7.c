/* Faça um programa que leia uma cadeia de caracteres em formato de data: DD/MM/AAAA;
    Crie uma função que receba esta data como parâmetro e que retorne o dia, o mês e o ano em três variáveis inteiras distintas. 
    Escreva os valores retornados no programa principal.
    Crie um a função que receba o ano como parâmetro e retorne se a data caiu em um ano bissexto. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separa(char *nasc, int *ano, int *mes, int *dia) {
    char A[5], M[3], D[3];
    
    strncpy(A,&nasc[6],4);
    A[4] = '\0';
    *ano = atoi(A);
    
    strncpy(M,&nasc[3],2);
    M[2] = '\0';
    *mes = atoi(M);
    
    strncpy(D,nasc,2);
    D[2] = '\0';
    *dia = atoi(D);
}
int ehBissexto(int ano) {
    if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))
        return 1;
    else
        return 0;
}
int main(void) {
    char nasc[10], m[10];
    int dia, mes, ano;
        
    printf("\nDigite a data de nascimento: ");
    scanf(" %s", nasc);
        
    separa(nasc, &ano, &mes, &dia);
    printf("\n\nTu nasceste no dia %d do mes %d", dia, mes);
    
    if (ehBissexto(ano))
        printf("\n\nO ano de %d eh bissexto!", ano);
    else
        printf("\n\nO ano de %d nao eh bissexto!", ano);

    return 0;
}