// src/reserva.c
#include "imports.h"
#include "reservas.h"

// metodo de iniciar a matriz de mesas
void inicializarMesas(Mesa matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j].ocupada = 0;
            matriz[i][j].nome[0] = '\0';
            matriz[i][j].status = 'L';
        }
    }
}

// método de exibir as mesas no painel
void exibirMesas(Mesa matriz[TAM][TAM]) {
    printf(
        "        Legendas: \n"
        "        L: Liberado/Livre\n"
        "        R: Reservado/Ocupado\n"
    );

    printf("\n        ");  // 8 espaços: alinha com o banner

    // Cabeçalho: números das colunas
    for (int col = 0; col < TAM; col++) {
        printf(" %2d ", col + 1);
    }
    printf("\n        ");

    // Linha separadora
    for (int col = 0; col < TAM; col++) {
        printf("----");
    }
    printf("\n");

    // Corpo da matriz
    for (int i = 0; i < TAM; i++) {
        printf("    %2d |", i + 1);  // Indentação + número da linha
        for (int j = 0; j < TAM; j++) {
            printf(" %2c ", matriz[i][j].status);
        }
        printf("\n");
    }

    printf("\n");
}



// Método de cancelamento de reserva por Codigo
void cancelarReservaPorCodigo(Mesa matriz[TAM][TAM], int codigo){
    int encontrou = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j].ocupada && matriz[i][j].codigo == codigo) {
                printf("        Reserva de %s cancelada na mesa [%d][%d].\n", matriz[i][j].nome, i, j);
                matriz[i][j].ocupada = 0;
                matriz[i][j].status = 'L';
                matriz[i][j].nome[0] = '\0';
                matriz[i][j].codigo = 0;
                encontrou = 1;
                break;
            }
        }
        if (encontrou) break;
    }

    if (!encontrou) {
        printf("        Codigo de reserva não encontrado.\n");
    }
}

// Método de cancelamento de reserva por linha e Coluna
void cancelarReserva(Mesa matriz[TAM][TAM], int linha, int coluna) {
    if (!matriz[linha][coluna].ocupada) {
        printf("        A mesa [%d][%d] ja esta livre.\n", linha, coluna);
    } else {
        printf("        Reserva de %s cancelada na mesa [%d][%d].\n", matriz[linha][coluna].nome, linha, coluna);
        matriz[linha][coluna].ocupada = 0;
        matriz[linha][coluna].status = 'L'; // volta pra livre
        matriz[linha][coluna].nome[0] = '\0';
    }
}


// método de reservar mesa
int reservarMesa(Mesa matriz[TAM][TAM], int linha, int coluna, const char* nome) {
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && !matriz[linha][coluna].ocupada) {
        matriz[linha][coluna].ocupada = 1;
        matriz[linha][coluna].status = 'R';
        matriz[linha][coluna].codigo = gerarCodigo(); 
        strncpy(matriz[linha][coluna].nome, nome, sizeof(matriz[linha][coluna].nome) - 1);
        matriz[linha][coluna].nome[sizeof(matriz[linha][coluna].nome) - 1] = '\0';
        return 1; // sucesso
    }
    return 0; // falha
}

// método pra gerar um codigo único do cliente
int gerarCodigo(){
    srand(time(NULL));
    int codigo = rand() % 9000 + 1000; // Gera número entre 1000 e 9999
    return codigo;
}