//
// Created by NiCo on 25/05/2025.
//

#ifndef CARRO_H_INCLUDED
#define CARRO_H_INCLUDED

typedef struct {
    char sit;
    int idPiloto;
    int anoFabricacao;
    char *chassi;
    char *equipe;
    char *fabricante;
    int ranking;
} rgCarro;

rgCarro Carro(int idPiloto, int anoFabricacao, char *chassi,char *equipe, char *fabricante, int ranking);
char *toStringCarro(rgCarro carro);

void importarCarros(rgCarro *lstCarro, int *nCarro);
void exportarCarros(rgCarro *lstCarro, int nCarro);


void cadastrarCarro(rgCarro *lstCarro, int *nCarro);
void listarCarros(rgCarro *lstCarro, int nCarro);
void excluirCarro(rgCarro *lstCarro, int nCarro);

#endif
