#include <stdio.h>
#include <stdlib.h>
#include "opcoes_autor.h"
#include "opcoes_livro.h"
#include "menu.h"
#include "geral.h"

int main() {
    fichaLivro lstLivro[100];
    fichaAutor lstAutor[100];
    int nLivro = 0;
    int nAutor = 0;
    int opc;

    do {
        cls();
        printf("<<<<< MENU PRINCIPAL >>>>>\n");
        printf("1 - Gerenciar Livros\n");
        printf("2 - Gerenciar Autores\n");
        printf("0 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                menuLivros(lstLivro, &nLivro);
                break;
            case 2:
                menuAutores(lstAutor, &nAutor);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOp��o inv�lida!\n");
                pause();
        }
    } while (opc != 0);

    return 0;
}
