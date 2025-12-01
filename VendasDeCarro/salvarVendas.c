#include <stdio.h>
#include "salvarVendas.h"

void salvarVendas(Venda *vendas, int totalVendas) {
    FILE *f = fopen("vendas.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir vendas.txt para escrita.\n");
        return;
    }

    for (int i = 0; i < totalVendas; i++) {
        fprintf(f, "%s;%s;%.2f;%s\n",
                vendas[i].placaCarro,
                vendas[i].cpfCliente,
                vendas[i].valorVenda,
                vendas[i].data);
    }

    fclose(f);
    printf("Vendas salvas com sucesso em vendas.txt!\n");
}
