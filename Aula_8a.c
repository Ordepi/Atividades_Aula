/* Faça um programa que leia o quadro de cargos e salários de uma empresa e que calcule a média salarial.
    Crie uma estrutura com os campos cargo e salário;
    Ao final do programa escreva os cargos que estão acima da média calculada; */
#include <stdio.h>

struct empresa {
    char cargo[100];
    float salario;
};
typedef struct empresa tyemp;

int main(void) {
    int i, carg = 0;
    float media = 0.0;

    do {
        printf("Informe quantos cargos possue sua empresa: ");
        scanf("%d", &carg);
    } while (carg < 1);
    
    tyemp vetinfo[carg];
    
    for (i = 0; i < carg; i++) {
        printf("Informe o nome do cargo: ");
        scanf(" %[^\n]s", vetinfo[i].cargo);
        printf("Informe o salario desse cargo: R$");
        scanf("%f", &vetinfo[i].salario);

        media += vetinfo[i].salario;
    }

    media /= carg;
    printf("\n\nOs cargos que recebem um salario acima de R$%.2f sao: ", media);
    
    for (i = 0; i < carg; i++)
        if (vetinfo[i].salario > media)
            printf("\n%s", vetinfo[i].cargo);

    return 0;
}