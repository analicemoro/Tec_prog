#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

typedef struct{
    char sit;
    int idAutor;
    int idLivro;
    char* titulo;
    int ano;
} fichaLivro;

fichaLivro Livro(int idAutor, char *titulo, int ano, int idLivro);

char getSitLivro(fichaLivro livro);
void setSitLivro(fichaLivro livro, char sit);

int getIdLivro(fichaLivro livro);
void setIdLivro(fichaLivro *livro, int idLivro);

int getIdAutorLivro(fichaLivro livro);
void setIdAutorLivro(fichaLivro *livro, int idAutor);

char *getTitulo(fichaLivro livro);
void setTitulo(fichaLivro *livro, char *titulo);

int getAno(fichaLivro livro);
void setAno(fichaLivro *pessoa, int ano);

int achouLivro(fichaLivro *lstLivro, int nLivro, int idLivro);
int sizeLivro(fichaLivro *lstLivro, int nLivro);
char *toStringLivro(fichaLivro livro);

#endif // LIVRO_H_INCLUDED
