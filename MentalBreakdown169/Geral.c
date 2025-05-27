//
// Created by NiCo on 25/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "Geral.h"

void cls(void) { system("cls"); }
void pause(void) { system("pause"); }
void esvaziar(void) { fflush(stdin); }

int confirmou(char *titulo) {
    char cf;
    esvaziar();
    printf("%s", titulo);
    scanf(" %c", &cf);
    return (cf == 'S' || cf == 's');
}

rgData dataNova(int d, int m, int a) {
    rgData dt;
    dt.dia = d;
    dt.mes = m;
    dt.ano = a;
    return dt;
}