#include <stdio.h>
#include <stdlib.h>
#include "opcoes_autor.h"
#include "opcoes_livro.h"
#include "geral.h"

void menuLivros(fichaLivro *lstLivro, int *nLivro) {
    int opc;
    do {
        cls();
        printf("<<<<< MENU DE LIVROS >>>>>\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Listar Livros\n");
        printf("3 - Excluir Livro\n");
        printf("4 - Importar Livros\n");
        printf("5 - Exportar Livros\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                entradaLivro(lstLivro, nLivro);
                break;
            case 2:
                listarLivros(lstLivro, *nLivro);
                break;
            case 3:
                excluirLivro(lstLivro, *nLivro);
                break;
            case 4:
                importarLivro(lstLivro, nLivro);
                break;
            case 5:
                exportarLivro(lstLivro, *nLivro);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
                pause();
        }
    } while (opc != 0);
}

void menuAutores(fichaAutor *lstAutor, int *nAutor) {
    int opc;
    do {
        cls();
        printf("<<<<< MENU DE AUTORES >>>>>\n");
        printf("1 - Cadastrar Autor\n");
        printf("2 - Listar Autores\n");
        printf("3 - Excluir Autor\n");
        printf("4 - Importar Autores\n");
        printf("5 - Exportar Autores\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                entradaAutor(lstAutor, nAutor);
                break;
            case 2:
                listarAutores(lstAutor, *nAutor);
                break;
            case 3:
                excluirAutor(lstAutor, *nAutor);
                break;
            case 4:
                importarAutor(lstAutor, nAutor);
                break;
            case 5:
                exportarAutor(lstAutor, *nAutor);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
                pause();
        }
    } while (opc != 0);
}
