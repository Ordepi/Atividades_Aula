#include <stdio.h>
#include <string.h>

#define tam 3

int main(void){
    char cod[tam], maior_cod[tam];
    float preco, maior = 0;

    printf("Informe o codigo do produto: ");
    scanf("%s", cod);
    
    while (strcmp(cod, "XXX") != 0){
        printf("Informe o preco do produto de codigo %s: R$", cod);
        scanf("%f", &preco);

        if (preco > maior){
            maior = preco;
            strcpy(maior_cod, cod);
        }

        printf("Informe o codigo do produto: ");
        scanf("%s", cod);
    }
 
    printf("O produto mais caro eh o de codigo %.3s, ele custa R$%.2f", maior_cod, maior);

    return 0;
}