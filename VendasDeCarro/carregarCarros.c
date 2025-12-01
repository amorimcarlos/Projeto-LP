#include <stdio.h>
#include "carregarCarros.h"

int carregarCarros(Carro *carros) {
    FILE *f = fopen("carros.txt", "r");
    if (!f) {
        printf("Arquivo carros.txt não encontrado.\n");
        return 0;
    }

    int i = 0;

    while (fscanf(f, " %[^;];%[^;];%[^;];%d;%[^;];%d;%[^;];%f\n",
                  carros[i].placa,
                  carros[i].marca,
                  carros[i].modelo,
                  &carros[i].anoModelo,
                  carros[i].cor,
                  &carros[i].quilometragem,
                  carros[i].combustivel,
                  &carros[i].valorVenda) == 8) {
        i++;
    }

    fclose(f);

    printf("%d carros carregados de carros.txt\n", i);
    return i;  // total de carros carregados
}
