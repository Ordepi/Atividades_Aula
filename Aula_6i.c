#include <stdio.h>
#include <string.h>

#define tam 20

int main(void) {
  float preco, maior = 0;
  char cod[tam], maior_cod[tam];
    
  printf("\nDigite o nome do produto: ");
  scanf(" %[^\n]s", cod);

  while (strcmp(cod,"XXX") != 0) {
    printf("\n Digite o preco do produto: R$");
    scanf("%f", &preco);
    
    if (preco > maior) {
      maior = preco;
      strcpy(maior_cod,cod);
    }
    
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]s", cod);
  }

  printf("\n\n O produto mais caro eh: %s", maior_cod);
  
  return 0;
}