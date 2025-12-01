#include <stdio.h>
#include <string.h>
#include "carregarVendas.h"

int carregarVendas(Venda *vendas) {

    FILE *f = fopen("vendas.txt", "r");
    if (f == NULL) {
        printf("Arquivo vendas.txt não encontrado. Nenhuma venda carregada.\n");
        return 0;
    }

    int i = 0;

    while (!feof(f)) {

        fscanf(f, "%[^;];%[^;];%f;%[^\n]\n",
            vendas[i].placaCarro,
            vendas[i].cpfCliente,
            &vendas[i].valorVenda,
            vendas[i].data
        );

        i++;
    }

    fclose(f);

    printf("%d vendas carregadas do arquivo vendas.txt\n", i);
    return i;   // total de vendas carregadas
}

