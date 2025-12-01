#include <stdio.h>
#include <string.h>
#include "buscarCarro.h"

int buscarCarro(Carro *carros, int totalCarros, char placa[]) {

    for (int i = 0; i < totalCarros; i++) {
        if (strcmp(carros[i].placa, placa) == 0) {
            return i;
        }
    }

    return -1;
}
