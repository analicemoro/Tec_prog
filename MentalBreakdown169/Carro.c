//
// Created by NiCo on 25/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carro.h"
#include "Geral.h"

rgCarro Carro(int idPiloto, int anoFabricacao, char *chassi, char *equipe, char *fabricante, int ranking) {
    rgCarro carro;
    carro.sit = 'X';
    carro.idPiloto = idPiloto;
    carro.anoFabricacao = anoFabricacao;
    carro.chassi = malloc(50);
    strcpy(carro.chassi, chassi);
    carro.equipe = malloc(50);
    strcpy(carro.equipe, equipe);
    carro.fabricante = malloc(50);
    strcpy(carro.fabricante, fabricante);
    carro.ranking = ranking;
    return carro;
}

char *toStringCarro(rgCarro carro) {
    char *result = malloc(250);
    sprintf(result,  "\nAno.................: %d"
                            "\nChassi..............: %s"
                            "\nEquipe..............: %s"
                            "\nFabricante do Motor.: %s"
                            "\nPosicao na Temporada: %d",
            carro.anoFabricacao,carro.chassi, carro.equipe, carro.fabricante, carro.ranking);
    return result;
}

void cadastrarCarro(rgCarro *lstCarro, int *nCarro) {
    int idPiloto, ano, ranking;
    char chassi[50], equipe[50], fabricante[50];
    cls();
    printf("Numero do Piloto: "); scanf("%d", &idPiloto);
    printf("Ano Fabricacao: "); scanf("%d", &ano);
    printf("Chassi: "); scanf(" %[^\n]", chassi);
    printf("Equipe: "); scanf(" %[^\n]", equipe);
    printf("Fabricante do Motor: "); scanf(" %[^\n]", fabricante);
    printf("Posicao na Temporada: "); scanf("%d", &ranking);
    lstCarro[(*nCarro)++] = Carro(idPiloto, ano, chassi, equipe, fabricante, ranking);
    pause();
}

void listarCarros(rgCarro *lstCarro, int nCarro) {
    printf("\n-------------Todos os Carros-------------");
    for(int i = 0; i < nCarro; i++) {
        if(lstCarro[i].sit != '*') {
            printf("%s\n\n", toStringCarro(lstCarro[i]));
        }
    }
    pause();
}

void excluirCarro(rgCarro *lstCarro, int nCarro) {
    int idPiloto, ano;
    printf("Digite o Numero do Piloto qual Pertence o Carro a excluir: ");
    scanf("%d", &idPiloto);
    printf("Digite o Ano do Carro a excluir: ");
    scanf("%d", &ano);
    for(int i = 0; i < nCarro; i++) {
        if(lstCarro[i].idPiloto == idPiloto && lstCarro[i].anoFabricacao == ano) {
            lstCarro[i].sit = '*';
        }
    }
    pause();
}

void importarCarros(rgCarro *lstCarro, int *nCarro) {
    FILE *f = fopen("carros.txt", "r");
    if (f) {
        char linha[256];
        while (fgets(linha, sizeof(linha), f)) {
            char sit;
            int idPiloto, ano, ranking;
            char chassi[50], equipe[50], fabricante[50];

            if (sscanf(linha, " %c|%d|%d|%49[^|]|%49[^|]|%49[^|]|%d",
                       &sit, &idPiloto, &ano, chassi, equipe, fabricante, &ranking) == 7) {
                rgCarro c = Carro(idPiloto, ano, chassi, equipe, fabricante, ranking);
                c.sit = sit;
                lstCarro[(*nCarro)++] = c;
                       }
        }
        fclose(f);
    }
}



void exportarCarros(rgCarro *lstCarro, int nCarro) {
    FILE *f = fopen("carros.txt", "w");
    if (f) {
        for (int i = 0; i < nCarro; i++) {
            //if (lstCarro[i].sit != '*') {
                fprintf(f, "%c|%d|%d|%s|%s|%s|%d\n",
                        lstCarro[i].sit,
                        lstCarro[i].idPiloto,
                        lstCarro[i].anoFabricacao,
                        lstCarro[i].chassi,
                        lstCarro[i].equipe,
                        lstCarro[i].fabricante,
                        lstCarro[i].ranking);
            //}
        }
        fclose(f);
    }
}
