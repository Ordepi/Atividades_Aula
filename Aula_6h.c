#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separa_data(char *dataNasc, int *dia, int *mes, int *ano) {
    
    char D[3], M[3], A[5];

    strncpy(D,dataNasc,2);
    D[2] = '\0';
    dataNasc = &dataNasc[3];
    
    strncpy(M,dataNasc,2);
    M[2] = '\0';
    dataNasc = &dataNasc[3];
    
    strncpy(A,dataNasc,4);
    A[4] = '\0';
    
    printf("\nD %s", D);
    printf("\nM %s", M);
    printf("\nA %s", A);
    
    *dia = atoi(D);
    *mes = atoi(M);
    *ano = atoi(A);
}
int ehBissexto(int ano) {
    if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))
        return 1;
    else
        return 0;
}
int main(void) {
    
    char dataNasc[10];
    int dia, mes, ano;
    
    printf("\nDigite a data de nascimento: ");
    scanf(" %s", dataNasc);
    
    separa_data(dataNasc, &dia, &mes, &ano);
    
    printf("\nA data de nascimento é: %d - %d - %d", dia, mes, ano);
    if (ehBissexto(ano))
        printf("\nO ano é bissexto!");
    else
        printf("\nO ano não é bissexto!");
    
    return 0;
}