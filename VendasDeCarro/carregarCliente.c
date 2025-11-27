#include <stdio.h>
#include <string.h>
#include "carregarCliente.h"

int carregarClientesTXT(Cliente *clientes) {

    FILE *f = fopen("clientes.txt", "r");
    if (f == NULL) {
        printf("Arquivo clientes.txt não encontrado. Nenhum cliente carregado.\n");
        return 0;
    }

    int i = 0;

    while (!feof(f)) {

        fscanf(f, "%[^;];%[^;];%[^;];%[^\n]\n",
            clientes[i].nome,
            clientes[i].cpf,
            clientes[i].telefone,
            clientes[i].email
        );

        i++;
    }

    fclose(f);

    printf("%d clientes carregados do arquivo clientes.txt\n", i);
    return i;  // total de clientes carregados
}

