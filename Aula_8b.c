/* Faça um programa que contenha uma função que receba duas estruturas do tido dma, cada uma representando uma data
válida, e que devolva o número de anos que decorreram entre as duas datas.
    struct dma {
        int dia, mes, ano;
    }; */
#include <stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};
typedef struct dma tydma;

int anosCorridos(tydma data1, tydma data2) {
    int anos;
    
    anos = data2.ano - data1.ano;
    
    if (data1.mes > data2.mes)
        anos--;
    else if (data1.mes == data2.mes && data1.dia > data2.dia)
        anos--;
    
    return anos;
}
int main(void) {
    tydma data1, data2;
    int anos;

    printf("\nDigite a primeira data, no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    printf("\nDigite a segunda data, no mesmo formato da primeira: ");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
    
    anos = anosCorridos(data1,data2);
    printf("\n\nSe passaram %d anos", anos);

    return 0;
}