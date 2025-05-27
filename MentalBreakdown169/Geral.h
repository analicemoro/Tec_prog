//
// Created by NiCo on 25/05/2025.
//

#ifndef GERAL_H_INCLUDED
#define GERAL_H_INCLUDED

void cls(void);
void pause(void);
void esvaziar(void);
int confirmou(char *titulo);

// Estrutura de dados
typedef struct {
    int dia;
    int mes;
    int ano;
} rgData;

rgData dataNova(int d, int m, int a);

#endif
