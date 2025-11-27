#include <stdio.h>
#include <string.h>
#include "atualizarCliente.h"
#include "clientes.h"

void atualizarCliente(Cliente *clientes, int totalClientes) {
    if (totalClientes == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    char cpf[20];
    printf("Digite o CPF do cliente que deseja atualizar: ");
    scanf("%19s", cpf);

    // Procurar o cliente pelo CPF
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {

            int opcao;
            printf("\nCliente encontrado!\n");
            printf("O que deseja atualizar?\n");
            printf("1 - Nome\n");
            printf("2 - Telefone\n");
            printf("3 - Email\n");
            printf("Opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Novo nome: ");
                    getchar(); // limpa buffer
                    fgets(clientes[i].nome, 60, stdin);

                    // remove o '\n'
                    for (int k = 0; clientes[i].nome[k] != '\0'; k++) {
                        if (clientes[i].nome[k] == '\n') {
                            clientes[i].nome[k] = '\0';
                            break;
                        }
                    }
                    break;

                case 2:
                    printf("Novo telefone: ");
                    scanf("%19s", clientes[i].telefone);
                    break;

                case 3:
                    printf("Novo email: ");
                    scanf("%39s", clientes[i].email);
                    break;

                default:
                    printf("Opcao invalida.\n");
                    return;
            }

            printf("\nCliente atualizado com sucesso.\n");
            return;
        }
    }

    printf("Cliente com CPF %s nao encontrado.\n", cpf);
}

