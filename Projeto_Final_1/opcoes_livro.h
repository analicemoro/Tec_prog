#ifndef OPCOES_LIVRO_H_INCLUDED
#define OPCOES_LIVRO_H_INCLUDED

#include "autor.h"
#include "livro.h"

void entradaLivro(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLIvro, int *nLivro);
void excluirLivro(fichaLivro *lstLivro, int nLivro);

void listarLivro(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLivro, int nLivro);

void importarLivro(fichaLivro *lstLivro, int *nLivro);
void exportarLivro(fichaLivro *lstLivro, int nLivro);

#endif // OPCOESLIVRO_H_INCLUDED
