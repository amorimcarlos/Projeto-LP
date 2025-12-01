#include <stdio.h>
#include "removerCliente.h"
#include "buscarCliente.h"
#include "salvarCliente.h"

void removerCliente(Cliente *clientes, int *totalClientes) {
    if (*totalClientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    char cpf[20];
    printf("CPF do cliente que deseja remover: ");
    scanf("%19s", cpf);

    int i = buscarCliente(clientes, *totalClientes, cpf);
    if (i == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }

    // "apaga" o cliente deslocando os seguintes
    for (int j = i; j < *totalClientes - 1; j++) {
        clientes[j] = clientes[j + 1];
    }

    (*totalClientes)--;

    salvarClientes(clientes, *totalClientes);

    printf("Cliente removido com sucesso.\n");
}
