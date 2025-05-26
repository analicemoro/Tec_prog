#include <stdio.h>
#include <string.h>
#include "autor.h"
#include "livro.h"

fichaLivro Livro(int idAutor, char *titulo, int ano, int idLivro){
    fichaLivro livro;

    livro.sit = 'A';
    livro.idAutor = idAutor;
    livro.idLivro = idLivro;
    livro.titulo = (char *)malloc(50);
    strcpy(livro.titulo, titulo);
    livro.ano = ano;

    return(livro);
}

char getSitLivro(fichaLivro livro){
    return(livro.sit);
}

void setSitLivro(fichaLivro livro, char sit){
    livro->sit = sit;
}

int getIdLivro(fichaLivro livro){
    return(livro.idLivro);
}

void setIdLivro(fichaLivro *livro, int idLivro){
    livro->idLivro = idLivro;
}

int getIdAutorLivro(fichaLivro livro) {
  return(livro.idAutor);
}

void setIdAutorLivro(fichaLivro *livro, int idAutor) {
  livro->idAutor = idAutor;
}

char *getTitulo(fichaLivro livro){
    char *titulo = malloc(50);
    strcpy(titulo, livro.titulo);
    return(titulo);
}

void setTitulo(fichaLivro *livro, char *titulo){
    strcpy(livro->titulo, titulo);
}

int getAno(fichaLivro livro){
    return(livro.ano);
}

void setAno(fichaLivro *pessoa, int ano){
    livro->ano = ano;
}

int achouLivro(fichaLivro *lstLivro, int nLivro, int idLivro){
    int i;
    for(i=0; i<nLivro; i++) {
    if ((getSitLivro(lstLivro[i]) != '*') &&
        (getIdLivro(lstLivro[i]) == idLivro)) {
       return(i);
    }
  }
  return(-1);
}

int sizeLivro(fichaLivro *lstLivro, int nLivro){
    int i, ctReg = 0;
    for(i=0; i<nLivro; i++) {
        if (getSitLivro(lstLivro[i]) != '*') {
            ctReg++;
        }
    }
    return(ctReg);
}

char *toStringLivro(fichaLivro livro){
    char ficha[500], *result = (char *)malloc(500);

  sprintf(ficha, "Identificação do livro: %d\n"
                 "Título................: %s\n"
                 "Identificação do autor: %d\n"
                 "Ano de publicação.....: %d",
    getIdLivro(livro),
    getTitulo(livro),
    idAutor,
    getAno(livro));

  strcpy(result, ficha);
  return(result);
}
