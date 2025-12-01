#include <stdio.h>
#include <locale.h>

//Carros
#include "adicionarCarro.h"
#include "listarCarros.h"
#include "atualizarCarro.h"
#include "buscarCarro.h"
#include "removerCarros.h"
#include "salvarCarros.h"
#include "carregarCarros.h"
#include "listarCarros.h"
#include "removerCarros.h"
#include "salvarCarros.h"

//Cliente
#include "adicionarCliente.h"
#include "atualizarCliente.h"
#include "buscarCliente.h"
#include "listarCliente.h"
#include "removerCliente.h"
#include "salvarCliente.h"
#include "carregarCliente.h"

//Vendas
#include "listarVendas.h"
#include "carregarVendas.h"
#include "registrarVenda.h"
#include "salvarVendas.h"

#define MAX_CARROS   100
#define MAX_CLIENTES 100
#define MAX_VENDAS   100

void menuCarros(Carro *listaCarros, int *totalCarros);
void menuClientes(Cliente *listaClientes, int *totalClientes);
void menuVendas(Venda *listaVendas, int *totalVendas,
                Carro *listaCarros, int *totalCarros,
                Cliente *listaClientes, int totalClientes);


int main() {
    Carro   listaCarros[MAX_CARROS];
    Cliente listaClientes[MAX_CLIENTES];
    Venda   listaVendas[MAX_VENDAS];
    setlocale(LC_ALL, "Portuguese");

    int totalCarros   = 0;
    int totalClientes = 0;
    int totalVendas   = 0;

    int opcao;

    do {
        printf("\n---------------- Concessionária Dominices ----------------\n");
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
                menuVendas(listaVendas, &totalVendas,
                           listaCarros, &totalCarros,
                           listaClientes, totalClientes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

// ---------------- MENU CARROS ----------------

void menuCarros(Carro *listaCarros, int *totalCarros) {
    int opcao;

    do {
        printf("\n--------------- MENU CARROS ---------------\n");
        printf("1 - Adicionar carro\n");
        printf("2 - Listar carros\n");
        printf("3 - Atualizar carro\n");
        printf("4 - Buscar carro por placa\n");
        printf("5 - Remover carro\n");
        printf("6 - Salvar carros\n");
        printf("7 - Carregar carros\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCarro(listaCarros, totalCarros);
                break;

            case 2:
                listarCarros(listaCarros, *totalCarros);
                break;

            case 3:
                atualizarCarro(listaCarros, *totalCarros);
                break;

            case 4: {
                char placa[10];
                printf("Digite a placa: ");
                scanf("%9s", placa);
                int pos = buscarCarro(listaCarros, *totalCarros, placa);
                if (pos == -1) {
                    printf("Carro nao encontrado.\n");
                }
                // se a função já imprime os dados, nem precisa fazer mais nada aqui
                break;
            }

            case 5:
                removerCarro(listaCarros, totalCarros);
                break;

            case 6:
                salvarCarros(listaCarros, *totalCarros);
                break;

            case 7:
                *totalCarros = carregarCarros(listaCarros);
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}

// ---------------- MENU CLIENTES ----------------

void menuClientes(Cliente *listaClientes, int *totalClientes) {
    int opcao;

    do {
        printf("\n------------- MENU CLIENTES --------------\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Atualizar cliente\n");
        printf("4 - Buscar cliente por CPF\n");
        printf("5 - Remover cliente\n");
        printf("6 - Salvar clientes\n");
        printf("7 - Carregar clientes\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(listaClientes, totalClientes);
                break;

            case 2:
                listarClientes(listaClientes, *totalClientes);
                break;

            case 3:
                atualizarCliente(listaClientes, *totalClientes);
                break;

            case 4: {
                char cpf[20];
                printf("CPF para buscar: ");
                scanf("%19s", cpf);
                buscarCliente(listaClientes, *totalClientes, cpf);
                // essa função já mostra os dados do cliente
                break;
            }

            case 5:
                removerCliente(listaClientes, totalClientes);
                break;

            case 6:
                salvarClientes(listaClientes, *totalClientes);
                break;

            case 7:
                *totalClientes = carregarClientes(listaClientes);
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}

// ---------------- MENU VENDAS ----------------

void menuVendas(Venda *listaVendas, int *totalVendas,
                Carro *listaCarros, int *totalCarros,
                Cliente *listaClientes, int totalClientes) {
    int opcao;

    do {
        printf("\n--------------- MENU VENDAS ---------------\n");
        printf("1 - Registrar venda\n");
        printf("2 - Listar vendas\n");
        printf("3 - Salvar vendas\n");
        printf("4 - Carregar vendas\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarVenda(listaVendas, totalVendas,
                               listaCarros, totalCarros,
                               listaClientes, totalClientes);
                break;

            case 2:
                listarVendas(listaVendas, *totalVendas);
                break;

            case 3:
                salvarVendas(listaVendas, *totalVendas);
                break;

            case 4:
                *totalVendas = carregarVendas(listaVendas);
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}
