#include <stdio.h>
#include <stdlib.h>
#include "Geral.h"
#include "Piloto.h"
#include "Carro.h"

#define maxTam 100

int main() {
    rgPiloto lstPiloto[maxTam];
    rgCarro lstCarro[maxTam];
    int nPiloto = 0, nCarro = 0;

    importarPilotos(lstPiloto, &nPiloto);
    importarCarros(lstCarro, &nCarro);

    printf(".-------------------------------------------------------------------------------------.\n");
    printf("| _____ _   _ _____ _   _ _____ _   _ ____  _   _                                     |\n");
    printf("||_   _| | | |_   _| | | |_   _| | | |  _ \\| | | |                                    |\n");
    printf("|  | | | | | | | | | | | | | | | | | | |_) | | | |                                    |\n");
    printf("|  | | | |_| | | | | |_| | | | | |_| |  _ <| |_| |                                    |\n");
    printf("|  |_|  \\___/  |_|  \\___/  |_|  \\___/|_| \\_\\\\___/                                     |\n");
    printf("|                                                                                     |\n");
    printf("| __  __    _    __  __ __     _______ ____  ____ _____  _    ____  ____  _____ _   _ |\n");
    printf("||  \\/  |  / \\   \\ \\/ / \\ \\   / / ____|  _ \\/ ___|_   _|/ \\  |  _ \\|  _ \\| ____| \\ | ||\n");
    printf("|| |\\/| | / _ \\   \\  /   \\ \\ / /|  _| | |_) \\___ \\ | | / _ \\ | |_) | |_) |  _| |  \\| ||\n");
    printf("|| |  | |/ ___ \\  /  \\    \\ V / | |___|  _ < ___) || |/ ___ \\|  __/|  __/| |___| |\\  ||\n");
    printf("||_|  |_/_/   \\_\\/_/\\_\\    \\_/  |_____|_| \\_\\____/ |_/_/   \\_\\_|   |_|   |_____|_| \\_||\n");
    printf("'-------------------------------------------------------------------------------------'\n");
    printf("\n------------------Cadastre Pilotos de F1 e os Carros o qual dirigiram------------------\n");

    int opcao;
    do {
        //cls();
        printf("\nSelecione uma opcao abaixo: ");
        printf(  "\n==> 1. Cadastrar Piloto"
                        "\n==> 2. Listar Pilotos"
                        "\n==> 3. Cadastrar Carro"
                        "\n==> 4. Listar Carros"
                        "\n==> 5. Excluir Piloto"
                        "\n==> 6. Excluir Carro"
                        "\n==> 0. Salvar e Sair"
                        "\nOpcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            cadastrarPiloto(lstPiloto, &nPiloto);
        } else if(opcao == 2) {
            listarPilotos(lstPiloto, nPiloto, lstCarro, nCarro);
        } else if(opcao == 3) {
            cadastrarCarro(lstCarro, &nCarro);
        } else if(opcao == 4) {
            listarCarros(lstCarro, nCarro);
        } else if(opcao == 5) {
            excluirPiloto(lstPiloto, nPiloto, lstCarro, nCarro);
        } else if(opcao == 6) {
            excluirCarro(lstCarro, nCarro);
        }

    } while(opcao != 0);

    exportarPilotos(lstPiloto, nPiloto);
    exportarCarros(lstCarro, nCarro);

    return 0;
}