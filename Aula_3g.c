/* Calcular o salário de um funcionário sabendo que ele foi contratado
por 1000 reais em 1995 e que no ano seguinte recebeu um
aumento de 0.1%, A partir daí, em cada ano o funcionário recebeu
um percentual de aumento do dobro do ano anterior. */
#include <stdio.h>

int main(void){
    int ano;
    double porcent = 0.1, salario = 1000; 

    printf("Voce deseja saber o valor do salario dele apos quantos anos: ");
    scanf("%d", &ano);

    for (int i = 0; i < ano; i++){
        salario *= (1 + porcent);
        porcent *= 2;
    }
        
    printf("O salario desse funcionario em %d eh: R$%.2lf", 1995 + ano, salario);

    return 0;
}