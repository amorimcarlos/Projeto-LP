#include <stdio.h>
#include "salvarCliente.h"

void salvarClientes(Cliente *clientes, int totalClientes) {
    FILE *f = fopen("clientes.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir clientes.txt para escrita.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        fprintf(f, "%s;%s;%s;%s\n",
                clientes[i].nome,
                clientes[i].cpf,
                clientes[i].telefone,
                clientes[i].email);
    }

    fclose(f);

    printf("Clientes salvos com sucesso em clientes.txt.\n");
}
