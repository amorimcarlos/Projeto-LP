#ifndef CARROS_H_INCLUDED
#define CARROS_H_INCLUDED

typedef struct {
    char placa[10];
    char marca[30];
    char modelo[30];
    int anoModelo;
    char cor[20];
    int quilometragem;
    char combustivel[15];
    float valorVenda;
} Carro;

#endif // CARROS_H_INCLUDED
