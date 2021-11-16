#include <stdio.h>
/*Preencher 2 vetores de X posições cada, com números inteiros. 
Fazer uma função que receba os dois vetores como parâmetros e que retorne a quantidade de posições
que possuem números distintos.*/
int posicoes_dif(int *v1, int *v2, int t) {
    int diferente = 0;

    for (int k = 0; k < t; k++)
        if (v1[k] != v2[k])
            diferente++;

    return diferente;
}
void preenche_vetor (int *vet, int t) {
    for (int i = 0; i < t; i++) {
        printf("Digite o valor da %dº posicao do vetor: ", i + 1);
        scanf("%d", &vet[i]);
    }
}
int main (void) {
    int tam;

    do {
        printf("Informe o tamanho dos vetores: ");
        scanf("%d", &tam);
    } while (tam < 1);

    int vetor1[tam], vetor2[tam];
    
    printf("\n\nPREENCHENDO VETOR 1\n");
    preenche_vetor(vetor1, tam);
    printf("\n\nPRENCHEENDO VETOR 2\n");
    preenche_vetor(vetor2, tam);
    
    printf("\n\nExistem %d diferencas entre os vetores", posicoes_dif(vetor1, vetor2, tam));

    return 0;
}