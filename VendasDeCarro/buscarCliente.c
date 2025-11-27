#include <string.h>
#include <stdio.h>
#include "buscarCliente.h"

int buscarCliente(Cliente *clientes, int totalClientes, char cpf[]) {

    for (int i = 0; i < totalClientes; i++) {

        if (strcmp(clientes[i].cpf, cpf) == 0) {

            printf("\n=== Cliente encontrado ===\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Email: %s\n", clientes[i].email);
            printf("==========================\n");

            return i;   // retorna o índice do cliente
        }
    }

    printf("\nCliente com CPF %s não encontrado.\n", cpf);
    return -1;
}
