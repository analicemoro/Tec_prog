#include <stdio.h>
#include "geral.h"
#include "autor.h"
#include "livro.h"
#include "opcoes_autor.h"

void entradaAutor(fichaAutor *lstAutor, int *nAutor){
    fichaAutor autor;
    int idAutor;
    char *nome = (char *)malloc(50);
    char *nacionalidade = (char *)malloc(50);

    while (1) {
        cls();
        printf("<<<<< CADASTRAR AUTORES >>>>>\n\n");
        printf("Identificação (0 para encerrar): ");
        scanf("%d", &idAutor);
            if (idAutor == 0)
               break;

        printf("\nNome do Autor.........: ");
        scanf(" %[^\n]s", nome);

        esvaziar();
        printf("Nacionalidade.............: ");
        scanf(" %[^\n]s", nacionalidade);

        if (confirmou("Confirma o cadastro? (S/*): ")) {
            autor = Autor(idAutor, nome, nacionalidade);
            lstAutor[*nAutor] = autor;
            *nAutor = *nAutor + 1;
            printf("<<<< Confirmado >>>>\n\n\n");
        }
        else {
            printf("<<<< Não Confirmado >>>>\n\n\n\n");
        }

        esvaziar();
        pause();
    }
}

void excluirAutor(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLivro, int nLivro){
    int i, idPessoa, posicao;
    while (1) {
        cls();
        printf("<<<<< EXCLUIR AUTORES >>>>>\n\n");
        printf("Identificação (0 para encerrar): ");
        scanf("%d", &idAutor);
        if (idAutor == 0)
           break;

        posicao = achouAutor(lstAutor, nAutor, idAutor);
        if (posicao != -1) {
           printf("%s\n\n", toStringAutor(lstAutor[posicao]));
           if (confirmou("Confirma a exclusão? (S/*): ")) {
              setSitAutor(&lstAutor[posicao], '*');
              for(i=0; i<nLivro; i++) {
                if (getIdAutorLivro(lstLivro[i]) == idAutor) {
                   setSitLivro(&lstLivro[i], '*');
                }
              }
              printf("<<<< Excluído >>>>\n\n");
           }
           else {
              printf("<<<< Não Excluído >>>>\n\n");
           }
        }
        else {
           printf("<<<< Nome não localizado >>>>\n\n");
        }
        esvaziar();
        pause();
    }
}

void listarAutor(fichaAutor *lstAutor, int nAutor){
    int n = sizeAutor(lstAutor, nAutor);
    int i, ctReg = 0, ctPag = 0, totPag = n / 5 + (((n % 5) == 0)?0:1);

    cabecalho("<<<<< LISTAR AUTORES >>>>> ", &ctPag, totPag, &ctReg);
    for(i=0; i<nAutor; i++) {
        if (getSitAutor(lstAutor[i]) != '*') {
            printf("%s\n\n", toStringAutor(lstAutor[i]));
            ctReg++;
            if (((ctReg == 5) && (ctPag < totPag))) {
              cabecalho("<<<<< LISTAR AUTORES >>>>> ", &ctPag, totPag, &ctReg);
           }
        }
    }
    pause();
}

void importarAutor(fichaAutor *lstAutor, int *nAutor){
    FILE *arq;
    arq = fopen("Autor.txt", "r");
    if (arq != NULL) {
        fichaAutor autor;
        int idAutor;
        char *nome = (char *)malloc(50);
        char *nacionalidade = (char *)malloc(50);

        fgets(nome, 50, arq);
        while (!feof(arq)) {
            nome[strlen(nome) - 1] = '\0';

            fgets(nacionaliade, 50, arq);
            nacionaliade[strlen(nacionaliade) - 1] = '\0';

            fscanf(arq, "%d\n", &idAutor);

            autor = Autor(idAutor, nome, nacionaliade);
            lstAutor[*nAutor] = autor;
            (*nAutor)++;

            fgets(nome, 50, arq);
        }

        fclose(arq);
        free(nome);
        free(nacionaliade);
    }

}
void exportarAutor(fichaAutor *lstAutor, int nAutor) {
    FILE *arq;
    arq = fopen("Autores.txt", "w");
    if (arq != NULL) {
        for (int i = 0; i < nAutor; i++) {
            fprintf(arq, "%d;%s;%s;%c\n",
                lstAutor[i].idAutor,
                lstAutor[i].nome,
                lstAutor[i].nacionalidade,
                lstAutor[i].sit);
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo para exportação.\n");
    }
}
