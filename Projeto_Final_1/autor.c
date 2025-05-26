#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autor.h"

fichaAutor Autor(int idAutor, char *nome, char *nacionalidade){
    fichaAutor autor;

    autor.sit = 'A';
    autor.idAutor = idAutor;
    autor.nome = (char *)malloc(50);
    strcpy(autor.nome, nome);
    autor.nacionalidade = (char *)malloc(50);
    strcpy(autor.nacionalidade, nacionalidade);

    return(autor);
}

char getSitAutor(fichaAutor autor){
    return(autor.sit);
}

void setSitAutor(fichaAutor *autor, char sit){
    autor->sit = sit;
}

int getIdAutor(fichaAutor autor){
    return(autor.idAutor);
}

void setIdAutor(fichaAutor *autor, int idAutor){
    autor->idAutor = idAutor;
}

char *getNome(fichaAutor autor){
    char *nome = malloc(50);
    strcpy(nome, autor.nome);
    return(nome);
}

void setNome(fichaAutor *autor, char *nome){
    strcpy(autor->nome, nome);
}

char *getNacionalidade(fichaAutor autor){
    char *nacionalidade = malloc(50);
    strcpy(nacionalidade, autor.nacionalidade);
    return(nacionalidade);
}

void setNacionalidade(fichaAutor *autor, char *nacionalidade){
    strcpy(autor->nacionalidade, nacionalidade);
}

int achouAutor(fichaAutor *lstAutor, int nAutor, int idAutor) {
  int i;
  for(i=0; i<nAutor; i++) {
    if ((getSitAutor(lstAutor[i]) != '*') &&
        (getIdAutor(lstAutor[i]) == idAutor)) {
       return(i);
    }
  }
  return(-1);
}

int sizeAutor(fichaAutor *lstAutor, int nAutor) {
  int i, ctReg = 0;
  for(i=0; i<nAutor; i++) {
    if (getSitAutor(lstAutor[i]) != '*') {
        ctReg++;
    }
  }
  return(ctReg);
}

char *toStringAutor(fichaAutor autor) {
  char ficha[500], *result = (char *)malloc(500);

  sprintf(ficha, "Identificação: %d\n"
                 "Nome.........: %s\n"
                 "Nacionalidade: %s",
    getIdAutor(autor),
    getNome(autor),
    getNacionalidade(autor));

  strcpy(result, ficha);
  return(result);
}
