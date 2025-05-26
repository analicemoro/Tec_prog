#ifndef OPCOES_AUTOR_H_INCLUDED
#define OPCOES_AUTOR_H_INCLUDED

#include "autor.h"
#include "livro.h"

void entradaAutor(fichaAutor *lstAutor, int *nAutor);

void excluirAutor(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLivro, int nLivro);
void listarAutor(fichaAutor *lstAutor, int nAutor);

void importarAutor(fichaAutor *lstAutor, int *nAutor);
void exportarAutor(fichaAutor *lstAutor, int nAutor);


#endif // OPCOESAUTOR_H_INCLUDED
