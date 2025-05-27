//
// Created by NiCo on 25/05/2025.
//

#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

#include "Geral.h"
#include "Carro.h"

typedef struct {
    char sit;
    int idPiloto;
    char *nome;
    char *localNascimento;
    rgData dtNasc;
} rgPiloto;

rgPiloto Piloto(int idPiloto, char *nome, char *localNascimento, rgData dtNasc);
char *toStringPiloto(rgPiloto piloto);

void importarPilotos(rgPiloto *lstPiloto, int *nPiloto);
void exportarPilotos(rgPiloto *lstPiloto, int nPiloto);

void cadastrarPiloto(rgPiloto *lstPiloto, int *nPiloto);
void listarPilotos(rgPiloto *lstPiloto, int nPiloto, rgCarro *lstCarro, int nCarro);
void excluirPiloto(rgPiloto *lstPiloto, int nPiloto, rgCarro *lstCarro, int nCarro);

#endif
