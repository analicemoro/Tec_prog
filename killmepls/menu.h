#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "opcoes_autor.h"
#include "opcoes_livro.h"
#include "geral.h"

void menuLivros(fichaLivro *lstLivro, int *nLivro);
void menuAutores(fichaAutor *lstAutor, int *nAutor);

#endif // MENU_H_INCLUDED
