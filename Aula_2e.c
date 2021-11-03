#include <stdio.h>

int main(void){

    char op;
    float A, B, resultado;
    
    printf("Digite um valor para A: ");
    scanf("%f", &A);
    printf("Digite um valor para B: ");
    scanf("%f", &B);

    printf("\n\nEscolha uma operacao: \n");
    printf("+ para soma\n");
    printf("- para subtracao\n");
    printf("* para multiplicacao\n");
    printf("/ para divisao\n");
    printf("==> ");
    scanf(" %c", &op);

    switch (op){
    case '+':
        resultado = A + B;
        break;
    case '-':
        resultado = A - B;
        break;
    case '*':
        resultado = A * B;
        break;
    case '/':
        resultado = A / B;
        break;

    default:
        printf("Opcao Invalida");
        break;
    }

    if(op == '+' || op == '-' || op == '*' || op == '/')
        printf("\nO resultado eh: %.2f\n", resultado);

    return 0;
}