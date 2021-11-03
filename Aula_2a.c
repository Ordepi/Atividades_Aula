/* Faça um programa que leia 3 notas e escreva a média aritmética */
#include <stdio.h>

int main(){

    float not1, not2, not3, mA;
    printf("Digite as tres notas do aluno: \n");
    scanf("%f %f %f", &not1, &not2, &not3);
    mA = (not1+not2+not3)/3;
    printf("A media aritmetrica eh: %.2f", mA);

    return 0;
}