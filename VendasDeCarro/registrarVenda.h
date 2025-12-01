#ifndef REGISTRARVENDA_H_INCLUDED
#define REGISTRARVENDA_H_INCLUDED
#include "vendas.h"
#include "carros.h"
#include "clientes.h"

void registrarVenda(
    Venda   *vendas,   int *totalVendas,
    Carro   *carros,   int *totalCarros,
    Cliente *clientes, int  totalClientes
);


#endif // REGISTRARVENDA_H_INCLUDED
