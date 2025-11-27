#include <stdio.h>
#include "salvarCarros.h"

void salvarCarrosTXT(Carro *carros, int total) {
    FILE *f = fopen("carros.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo carros.txt.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s;%s;%s;%d;%s;%d;%s;%.2f\n",
            carros[i].placa,
            carros[i].marca,
            carros[i].modelo,
            carros[i].anoModelo,
            carros[i].cor,
            carros[i].quilometragem,
            carros[i].combustivel,
            carros[i].valorVenda
        );
    }

    fclose(f);
    printf("Carros salvos com sucesso.\n");
}

