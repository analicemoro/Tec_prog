#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geral.h"
#include "autor.h"
#include "livro.h"
#include "opcoes_livro.h"

void entradaLivro(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLIvro, int *nLivro){
    fichaLivro livro;
    int idLivro, ano;
    char *titulo = (char *)malloc(50);

    while (1) {
        cls();
        printf("<<<<< CADASTRAR LIVROS >>>>>\n\n");
        printf("Identifica��o (0 para encerrar): ");
        scanf("%d", &idLivro);
        if (idLivro == 0)
            break;

        printf("\nT�tulo do Livro.........: ");
        scanf(" %[^\n]s", titulo);

        esvaziar();
        printf("Ano de Publica��o.......: ");
        scanf("%d", &ano);

        if (confirmou("Confirma o cadastro? (S/*): ")) {
            livro = Livro(idLivro, titulo, ano);
            lstLivro[*nLivro] = livro;
            (*nLivro)++;
            printf("<<<< Confirmado >>>>\n\n\n");
        } else {
            printf("<<<< N�o Confirmado >>>>\n\n\n\n");
        }

        esvaziar();
        pause();
    }

    free(titulo);
}

void excluirLivro(fichaLivro *lstLivro, int nLivro) {
    int id, i, encontrou = 0;

    cls();
    printf("<<<<< EXCLUIR LIVRO >>>>>\n\n");
    printf("Informe o ID do livro a ser exclu�do: ");
    scanf("%d", &id);

    for (i = 0; i < nLivro; i++) {
        if (lstLivro[i].idLivro == id && lstLivro[i].sit == 'A') {
            printf("\nLivro encontrado:\n");
            printf("ID....: %d\n", lstLivro[i].idLivro);
            printf("T�tulo: %s\n", lstLivro[i].titulo);
            printf("Ano...: %d\n", lstLivro[i].anoDePublicacao);

            if (confirmou("Confirma a exclus�o? (S/*): ")) {
                lstLivro[i].sit = '*';  // Exclus�o l�gica
                printf("<<<< Livro exclu�do logicamente >>>>\n");
            } else {
                printf("<<<< Exclus�o cancelada >>>>\n");
            }

            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("\nLivro com ID %d n�o encontrado ou j� exclu�do.\n", id);
    }

    esvaziar();
    pause();
}


void listarLivro(fichaAutor *lstAutor, int nAutor, fichaLivro *lstLivro, int nLivro){
    int n = sizeLivro(lstLivro, nLivro);
    int i, posicao, ctReg = 0, ctPag = 0, totPag = n / 3 + (((n % 3) == 0)?0:1);
    cabecalho("<<<<< LISTAR LIVROS >>>>>", &ctPag, totPag, &ctReg);
    for(i=0; i<nLivro; i++) {
      if (getSitLivro(lstLivro[i]) != '*') {
         posicao = achouAutor(lstAutor, nAutor, getIdAutorLivro(lstLivro[i]));
         if (posicao != -1) {
            printf("%s\n\n", toStringLivro(lstLivro[i], lstAutor[posicao]));
            ctReg++;
            if (((ctReg == 3) && (ctPag < totPag))) {
               cabecalho("<<<<< LISTAR LIVROS >>>>>", &ctPag, totPag, &ctReg);
            }
         }
      }
    }
    pause();
}

void importarLivro(fichaLivro *lstLivro, int *nLivro) {
    FILE *arq = fopen("Livros.txt", "r");
    if (arq != NULL) {
        fichaLivro livro;
        while (fscanf(arq, "%d;%49[^;];%d;%c\n",
                      &livro.idLivro,
                      livro.titulo,
                      &livro.anoDePublicacao,
                      &livro.sit) == 4) {
            lstLivro[*nLivro] = livro;
            (*nLivro)++;
        }
        fclose(arq);
    } else {
        printf("Arquivo 'Livros.txt' n�o encontrado.\n");
    }
}

void exportarLivro(fichaLivro *lstLivro, int nLivro) {
    FILE *arq = fopen("Livros.txt", "w");
    if (arq != NULL) {
        for (int i = 0; i < nLivro; i++) {
            fprintf(arq, "%d;%s;%d;%c\n",
                lstLivro[i].idLivro,
                lstLivro[i].titulo,
                lstLivro[i].anoDePublicacao,
                lstLivro[i].sit);
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo para exporta��o.\n");
    }
}
