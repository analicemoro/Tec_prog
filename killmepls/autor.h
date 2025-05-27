#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

typedef struct{
    char sit; // * - Exclu�do, A - Ativo
    int idAutor;
    char* nome;
    char* nacionalidade;
} fichaAutor;

fichaAutor Autor(int idAutor, char *nome, char *nacionalidade);

char getSitAutor(fichaAutor autor);
void setSitAutor(fichaAutor autor, char sit);

int getIdAutor(fichaAutor autor);
void setIdAutor(fichaAutor *autor, int idAutor);

char *getNome(fichaAutor autor);
void setNome(fichaAutor *pessoa, char *nome);

char *getNacionalidade(fichaAutor autor);
void setNacionalidade(fichaAutor *autor, char *nacionalidade);

int achouAutor(fichaAutor *lstAutor, int nAutor, int idAutor);
int sizeAutor(fichaAutor *lstAutor, int nAutor);
char *toStringAutor(fichaAutor autor);

#endif // AUTOR_H_INCLUDED
