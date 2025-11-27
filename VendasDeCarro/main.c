#include <stdio.h>

#include "carros.h"
#include "clientes.h"
#include "vendas.h"

#include "listarCarros.h"
#include "removerCarros.h"
#include "salvarCarros.h"

#include "adicionarCliente.h"
#include "atualizarCliente.h"
#include "buscarCliente.h"
#include "carregarCliente.h"

#include "listarVendas.h"
#include "carregarVendas.h"

#define MAX_CARROS   100
#define MAX_CLIENTES 100
#define MAX_VENDAS   100

void menuCarros(Carro *listaCarros, int *totalCarros);
void menuClientes(Cliente *listaClientes, int *totalClientes);
void menuVendas(Venda *listaVendas, int *totalVendas);

int main() {
    Carro   listaCarros[MAX_CARROS];
    Cliente listaClientes[MAX_CLIENTES];
    Venda   listaVendas[MAX_VENDAS];

    int totalCarros   = 0;
    int totalClientes = 0;
    int totalVendas   = 0;

    int opcao;

    do {
        printf("\n============= MENU PRINCIPAL =============\n");
        printf("1 - Menu de Carros\n");
        printf("2 - Menu de Clientes\n");
        printf("3 - Menu de Vendas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuCarros(listaCarros, &totalCarros);
                break;
            case 2:
                menuClientes(listaClientes, &totalClientes);
                break;
            case 3:
                menuVendas(listaVendas, &totalVendas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

void menuCarros(Carro *listaCarros, int *totalCarros) {
    int opcao;

    do {
        printf("\n--------------- MENU CARROS ---------------\n");
        printf("1 - Listar carros\n");
        printf("2 - Remover carro\n");
        printf("3 - Salvar carros (TXT)\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarCarros(listaCarros, *totalCarros);
                break;
            case 2:
                removerCarro(listaCarros, totalCarros);
                break;
            case 3:
                salvarCarrosTXT(listaCarros, *totalCarros);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}

void menuClientes(Cliente *listaClientes, int *totalClientes) {
    int opcao;

    do {
        printf("\n------------- MENU CLIENTES --------------\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Atualizar cliente\n");
        printf("3 - Buscar cliente por CPF\n");
        printf("4 - Carregar clientes (TXT)\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(listaClientes, totalClientes);
                break;
            case 2:
                atualizarCliente(listaClientes, *totalClientes);
                break;
            case 3: {
                char cpf[20];
                printf("CPF para buscar: ");
                scanf("%19s", cpf);
                buscarCliente(listaClientes, *totalClientes, cpf);
                break;
            }
            case 4:
                *totalClientes = carregarClientesTXT(listaClientes);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}

void menuVendas(Venda *listaVendas, int *totalVendas) {
    int opcao;

    do {
        printf("\n--------------- MENU VENDAS ---------------\n");
        printf("1 - Listar vendas\n");
        printf("2 - Carregar vendas (TXT)\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarVendas(listaVendas, *totalVendas);
                break;
            case 2:
                *totalVendas = carregarVendasTXT(listaVendas);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}
