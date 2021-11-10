/* Faça um programa imprima na tela um Menu que permita o usuário escolher as seguintes operações: +, -, /, *.
Se um operador inválido for digitado deve ser impresso um erro
Se o usuário digitar ! o programa deve ser finalizado
Se o usuário escolher uma das quatro operações, o programa deve
ler dois números reais e efetuá-los
Faça funções para escrever o Menu, realizar a operação e verificar se
o operador é válido */
#include <stdio.h>

void menu() {
    
    printf("\n\nEscolha uma operacao: \n");
    printf("+ para adicao\n");
    printf("- para subtracao\n");
    printf("* para multiplicacao\n");
    printf("/ para divisao\n");
    printf("! para encerrar\n");
    printf("===> ");

}
int opValido(char op){

    if (op == '+'|| op == '-'|| op == '/'|| op == '*' || op == '%' || op == '$' || op == '!')
        return 1;
    else
        return 0;
}
void operacao(int A, int B, char op) {
    
    switch (op) {
        case '+': 
            printf("\nA soma eh: %d\n", A + B);
            break;
        case '-': 
            printf("\nA subtracao eh: %d\n", A - B);
            break;
        case '*': 
            printf("\nA multiplicacao eh: %d\n", A * B);
            break;
        case '/': 
            if (B!=0)
                printf("\nA divisao eh: %.2f\n", (A / (B * 1.0)));
            else
                printf("\nA divisao nao pode ser realizada!\n");
            break;
    }
}
int main(void) {
    
    char op;
    int A,B;
    
    menu();
    scanf(" %c", &op);
    while (op != '!')  {
        if (opValido(op)) 
        {
            printf("Digite um valor para A : ");
            scanf("%d", &A);
            printf("Digite um valor para B : ");
            scanf("%d", &B);
            operacao(A,B,op);
        } 
        else 
            printf("\n\nEsta opcao eh invalida!");
        menu();
        scanf(" %c", &op);
    }

    return 0;
}