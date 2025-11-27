#include <stdio.h>
#include "adicionarCliente.h"

void adicionarCliente(Cliente *clientes, int *totalClientes) {
    int i = *totalClientes;

    printf("\n------------- Cadastro de Cliente -------------\n");

    printf("Nome: ");
    getchar();  // limpa o \n que sobrou do scanf anterior
    fgets(clientes[i].nome, 60, stdin);

    // tirar o \n do final do nome, se tiver
    int j = 0;
    while (clientes[i].nome[j] != '\0') {
        if (clientes[i].nome[j] == '\n') {
            clientes[i].nome[j] = '\0';
            break;
        }
        j++;
    }

    printf("CPF: ");
    scanf("%19s", clientes[i].cpf);

    printf("Telefone: ");
    scanf("%19s", clientes[i].telefone);

    printf("Email: ");
    scanf("%39s", clientes[i].email);

    (*totalClientes)++;

    printf("\nCliente cadastrado com sucesso.\n");
}

