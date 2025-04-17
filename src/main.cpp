// src/main.c
#include "imports.h"
#include "reservas.h"

Mesa restaurante[TAM][TAM];

void msg(const char* mensagem),  
banner(const char* tituloSecao),
limparTela(), menuPrincipal(),
iniciarSistema(), esperarTecla();

int main() {

    iniciarSistema();

    return 0;
}

void iniciarSistema(){
    inicializarMesas(restaurante);

    int op;
    do {
        limparTela();             // limpa a tela antes de exibir o menu
        banner("Menu Pincipal");           // mostra o banner no menu

        menuPrincipal();
        scanf("%d", &op);

        int linha, coluna;
        char nome[50];

        switch (op) {
            case 1:
                limparTela();
                banner("Reservando Mesa.."); // mostra o banner na tela de reserva
                msg("Linha");
                scanf("%d", &linha);
                msg("Coluna");
                scanf("%d", &coluna);
                msg("Nome");
                scanf(" %49[^\n]", nome);
                if (reservarMesa(restaurante, linha, coluna, nome)) {
                    restaurante[linha][coluna].codigo = gerarCodigo(); 
                    printf("       Reserva realizada com sucesso! Seu cod: '%d'\n", restaurante[linha][coluna].codigo);
                } else {
                    printf("       Não foi possivel reservar a mesa.\n");
                }
                esperarTecla();
                break;

            case 2:
                limparTela();
                banner("Cancelamento de Reserva"); // mostra o banner na tela de cancelamento
                printf("\n"
                "        [1] Cancelar por linha e coluna\n"
                );
                printf("        [2] Cancelar por codigo\n");

                int subop;
                msg("Escolha uma opcao");
                scanf("%d", &subop);

                if (subop == 1) {
                    msg("Linha da mesa a cancelar");
                    scanf("%d", &linha);
                    msg("Coluna da mesa a cancelar");
                    scanf("%d", &coluna);
                    cancelarReserva(restaurante, linha, coluna);
                } else if (subop == 2) {
                    int codigo;
                    msg("Digite o codigo da reserva");
                    scanf("%d", &codigo);
                    cancelarReservaPorCodigo(restaurante, codigo);
                } else {
                    printf("Opcao invalida.\n");
                }
                esperarTecla();
                break;

            case 3:
                limparTela();
                banner("Exibindo Mesas!"); // mostra o banner antes de exibir as mesas
                exibirMesas(restaurante);
                esperarTecla();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (op != 0);
}


void banner(const char* tituloSecao) {
    printf(
        "\n"
        "       ======================================\n"
        "       +    Restaurante do WMota Bistro     +\n"
        "       ======================================\n"
    );
    
    if (tituloSecao != NULL && tituloSecao[0] != '\0') {
        printf(
            "\n"
            "        %s\n\n", tituloSecao
        );
    }
}

void msg(const char* mensagem){
    if(mensagem!=NULL && mensagem[0] != '\0'){
        printf(
            "       %s: ", 
            mensagem
        );
    }
}

void menuPrincipal(){
    printf(
        "\n"
        "        ----- Menu -----\n\n"
        "        [1] Reservar mesa\n"
        "        [2] Cancelar reserva\n"
        "        [3] Exibir mesas\n"
        "        [0] Sair\n"
        ""
        "        Escolha uma opcao: "
    );
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void esperarTecla() {
    printf("\nPressione qualquer tecla para continuar...");
    fflush(stdout);  // garante que a mensagem aparece antes da espera
    getchar();
}