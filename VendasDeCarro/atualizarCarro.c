#include <stdio.h>
#include <string.h>
#include "atualizarCarro.h"
#include "buscarCarro.h"
#include "salvarCarros.h"

void atualizarCarro(Carro *carros, int totalCarros) {
    if (totalCarros == 0) {
        printf("\nNenhum carro cadastrado.\n");
        return;
    }

    char placa[10];
    printf("Placa do carro que deseja atualizar: ");
    scanf("%9s", placa);

    // usa a função de busca por placa
    int i = buscarCarro(carros, totalCarros, placa);

    if (i == -1) {
        printf("Carro não encontrado.\n");
        return;
    }

    printf("\nCarro encontrado: %s %s (%d)\n",
           carros[i].marca, carros[i].modelo, carros[i].anoModelo);

    printf("Nova cor: ");
    scanf("%19s", carros[i].cor);

    printf("Novo km: ");
    scanf("%d", &carros[i].quilometragem);

    printf("Novo combustível: ");
    scanf("%14s", carros[i].combustivel);

    printf("Novo valor de venda: ");
    scanf("%f", &carros[i].valorVenda);

    // salva tudo em TXT
    salvarCarros(carros, totalCarros);

    printf("\nCarro atualizado com sucesso.\n");
}
