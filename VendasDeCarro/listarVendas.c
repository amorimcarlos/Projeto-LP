#include <stdio.h>
#include "listarVendas.h"

void listarVendas(Venda *vendas, int totalVendas) {

    if (totalVendas == 0) {
        printf("\nNenhuma venda registrada.\n");
        return;
    }

    printf("\n------------- LISTA DE VENDAS -------------\n");

    for (int i = 0; i < totalVendas; i++) {
        printf("\nVenda %d:\n", i + 1);
        printf("Placa do carro: %s\n", vendas[i].placaCarro);
        printf("CPF do cliente: %s\n", vendas[i].cpfCliente);
        printf("Valor da venda: R$ %.2f\n", vendas[i].valorVenda);
        printf("Data: %s\n", vendas[i].data);
    }

    printf("\n--------------------------\n");
}

