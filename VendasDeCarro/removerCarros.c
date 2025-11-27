#include <stdio.h>
#include <string.h>
#include "removerCarros.h"

void removerCarro(Carro *carros, int *total) {
    if (*total == 0) {
        printf("\nNenhum carro cadastrado.\n");
        return;
    }

    char placa[10];
    printf("Digite a placa do carro que você deseja remover: ");
    scanf("%s", placa);

    for (int i = 0; i < *total; i++) {
        if (strcmp(carros[i].placa, placa) == 0) {

            // Desloca os elementos da lista para "apagar" o carro
            for (int j = i; j < *total - 1; j++) {
                carros[j] = carros[j + 1];
            }

            (*total)--;

            printf("Carro removido com a placa %s sucesso.\n", placa);
            return;
        }
    }

    printf("Carro com placa %s nao encontrado.\n", placa);
}
