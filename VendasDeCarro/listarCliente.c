#include <stdio.h>
#include "listarCliente.h"

void listarClientes(Cliente *clientes, int totalClientes) {

    if (totalClientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n-----------\ LISTA DE CLIENTES -----------\n\n");

    for (int i = 0; i < totalClientes; i++) {
        printf("%s | %s | %s | %s\n",
               clientes[i].nome,
               clientes[i].cpf,
               clientes[i].telefone,
               clientes[i].email);
    }

    printf("\n----------------------------------n");
}
