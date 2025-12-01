#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registrarVenda.h"
#include "buscarCarro.h"
#include "buscarCliente.h"
#include "salvarCarros.h"
#include "salvarVendas.h"

void registrarVenda(
    Venda   *vendas,   int *totalVendas,
    Carro   *carros,   int *totalCarros,
    Cliente *clientes, int  totalClientes
) {
    if (*totalCarros == 0 || totalClientes == 0) {
        printf("\nNao ha carros ou clientes cadastrados para registrar venda.\n");
        return;
    }

    char placa[10], cpf[20];

    printf("Placa do carro: ");
    scanf("%9s", placa);

    printf("CPF do cliente: ");
    scanf("%19s", cpf);

    // busca carro pela placa
    int idxCarro = buscarCarro(carros, *totalCarros, placa);

    // busca cliente pelo CPF
    int idxCliente = buscarCliente(clientes, totalClientes, cpf);

    if (idxCarro == -1 || idxCliente == -1) {
        printf("Erro na venda: carro ou cliente nao encontrado.\n");
        return;
    }

    Venda v;

    // copia placa e cpf
    strcpy(v.placaCarro, carros[idxCarro].placa);
    strcpy(v.cpfCliente, clientes[idxCliente].cpf);

    // usa o valor de venda do carro
    v.valorVenda = carros[idxCarro].valorVenda;

    // gera data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(v.data, "%02d/%02d/%04d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // salva no vetor de vendas
    vendas[*totalVendas] = v;
    (*totalVendas)++;

    // opcional: se quiser marcar como "vendido", precisa recolocar um campo na struct
    // por enquanto, só registra a venda e salva

    salvarVendas(vendas, *totalVendas);
    salvarCarros(carros, *totalCarros);

    printf("\nVenda registrada com sucesso.\n");
}
