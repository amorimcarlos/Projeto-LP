#include <stdio.h>
#include "listarCarros.h"

void listarCarros(Carro *carros, int total) {

    if (total == 0) {
        printf("\nNenhum carro cadastrado.\n");
        return;
    }

    printf("\n------------- LISTA DE CARROS -------------\n");

    for (int i = 0; i < total; i++) {
        printf("\nCarro %d:\n", i + 1);
        printf("Placa: %s\n", carros[i].placa);
        printf("Marca: %s\n", carros[i].marca);
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Ano modelo: %d\n", carros[i].anoModelo);
        printf("Cor: %s\n", carros[i].cor);
        printf("Quilometragem: %d km\n", carros[i].quilometragem);
        printf("Combustivel: %s\n", carros[i].combustivel);
        printf("Valor de venda: R$ %.2f\n", carros[i].valorVenda);
    }

    printf("---------------------------------------\n");
}
