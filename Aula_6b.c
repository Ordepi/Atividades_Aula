#include <stdio.h>
/*Ler N notas dos alunos de uma turma e calcular a média.
Ao final imprimir a quantidade de alunos que ficou acima da média calculada.*/
int main (void) {
    int tam, quantidade = 0;

    do {
        printf("Informe o numero de notas: ");
        scanf("%d", &tam);
    } while (tam <= 0);
    
    float notas[tam], variavel = 0.0, media;

    for (int i = 0; i < tam; i++) {
        printf("Digite a nota do %dº aluno: ", i + 1);
        scanf("%f", &notas[i]);
        variavel += notas[i];
    }
    
    media = (variavel / tam);
    printf("\n\nA media da turma eh de %.2f pontos", media);
    printf("\n\n");

    for (int j = 0; j < tam; j++)
        if (notas[j] > media)
            quantidade++;
    printf("%d alunos ficaram acima da media", quantidade);

    return 0;
}