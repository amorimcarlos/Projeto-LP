#include <stdio.h>
#include "adicionarCarro.h"

void adicionarCarro(Carro *carros, int *totalCarros) {
    Carro c;

    printf("Placa: ");
    scanf("%9s", c.placa);
    printf("Marca: ");
    scanf("%29s", c.marca);
    printf("Modelo: ");
    scanf("%29s", c.modelo);

    printf("Ano modelo: ");
    scanf("%d", &c.anoModelo);
    printf("Cor: ");
    scanf("%19s", c.cor);
    printf("KM: ");
    scanf("%d", &c.quilometragem);
    printf("Combustível: ");
    scanf("%14s", c.combustivel);
    printf("Valor de venda: ");
    scanf("%f", &c.valorVenda);
    carros[*totalCarros] = c;
    (*totalCarros)++;

    printf("\nCarro cadastrado com sucesso!\n");
}
