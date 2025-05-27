//
// Created by NiCo on 25/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Piloto.h"
#include "Geral.h"

rgPiloto Piloto(int idPiloto, char *nome, char *localNascimento, rgData dtNasc) {
    rgPiloto piloto;
    piloto.sit = 'X';
    piloto.idPiloto = idPiloto;
    piloto.nome = malloc(50);
    strcpy(piloto.nome, nome);
    piloto.localNascimento = malloc(50);
    strcpy(piloto.localNascimento, localNascimento);
    piloto.dtNasc = dtNasc;
    return piloto;
}

char *toStringPiloto(rgPiloto piloto) {
    char *result = malloc(200);
    sprintf(result,  "\n-----------------Piloto-----------------"
                            "\nNumero do Piloto: %d"
                            "\nNome............: %s"
                            "\nNascimento......: %02d/%02d/%04d"
                            "\nLocal...........: %s",
            piloto.idPiloto, piloto.nome, piloto.dtNasc.dia, piloto.dtNasc.mes, piloto.dtNasc.ano, piloto.localNascimento);
    return result;
}

void cadastrarPiloto(rgPiloto *lstPiloto, int *nPiloto) {
    int id, d, m, a;
    char nome[50], local[50];
    cls();
    printf("Numero: "); scanf("%d", &id);
    printf("Nome: "); scanf(" %[^\n]", nome);
    printf("Local Nascimento: "); scanf(" %[^\n]", local);
    printf("Data Nascimento (d m a): "); scanf("%d %d %d", &d, &m, &a);
    lstPiloto[(*nPiloto)++] = Piloto(id, nome, local, dataNova(d, m, a));
    pause();
}

void listarPilotos(rgPiloto *lstPiloto, int nPiloto, rgCarro *lstCarro, int nCarro) {
    for(int i = 0; i < nPiloto; i++) {
        if(lstPiloto[i].sit != '*') {
            printf("%s\n", toStringPiloto(lstPiloto[i]));
            printf("\n-----------------Carros-----------------");
            for(int j = 0; j < nCarro; j++) {
                if(lstCarro[j].sit != '*' && lstCarro[j].idPiloto == lstPiloto[i].idPiloto) {
                    printf("%s\n", toStringCarro(lstCarro[j]));
                }
            }
            printf("\n");
        }
    }
    pause();
}

void excluirPiloto(rgPiloto *lstPiloto, int nPiloto, rgCarro *lstCarro, int nCarro) {
    int id;
    printf("Digite o Numero do Piloto a excluir: ");
    scanf("%d", &id);
    for(int i = 0; i < nPiloto; i++) {
        if(lstPiloto[i].idPiloto == id) {
            lstPiloto[i].sit = '*';
            for(int j = 0; j < nCarro; j++) {
                if(lstCarro[j].idPiloto == id) {
                    lstCarro[j].sit = '*';
                }
            }
        }
    }
    pause();
}

void importarPilotos(rgPiloto *lstPiloto, int *nPiloto) {
    FILE *f = fopen("pilotos.txt", "r");
    if (f) {
        char linha[256];
        while (fgets(linha, sizeof(linha), f)) {
            char sit;
            int id, d, m, a;
            char nome[50], local[50];

            if (sscanf(linha, " %c|%d|%49[^|]|%49[^|]|%d|%d|%d",
                       &sit, &id, nome, local, &d, &m, &a) == 7) {
                rgPiloto p = Piloto(id, nome, local, dataNova(d, m, a));
                p.sit = sit;
                lstPiloto[(*nPiloto)++] = p;
                       }
        }
        fclose(f);
    }
}

void exportarPilotos(rgPiloto *lstPiloto, int nPiloto) {
    FILE *f = fopen("pilotos.txt", "w");
    if (f) {
        for (int i = 0; i < nPiloto; i++) {
            //if (lstPiloto[i].sit != '*') {
                fprintf(f, "%c|%d|%s|%s|%d|%d|%d\n",
                        lstPiloto[i].sit,
                        lstPiloto[i].idPiloto,
                        lstPiloto[i].nome,
                        lstPiloto[i].localNascimento,
                        lstPiloto[i].dtNasc.dia,
                        lstPiloto[i].dtNasc.mes,
                        lstPiloto[i].dtNasc.ano);
            //}
        }
        fclose(f);
    }
}
