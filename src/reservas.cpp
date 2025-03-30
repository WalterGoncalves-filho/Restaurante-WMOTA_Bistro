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
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j].ocupada)
                printf("[%c]", matriz[i][j].status);
            else
                printf("[%c]", matriz[i][j].status);
        }
        printf("\n");
    }
    printf("\n");
}

// método de reservar mesa
int reservarMesa(Mesa matriz[TAM][TAM], int linha, int coluna, const char* nome) {
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && !matriz[linha][coluna].ocupada) {
        matriz[linha][coluna].ocupada = 1;
        matriz[linha][coluna].status = 'R';
        strncpy(matriz[linha][coluna].nome, nome, sizeof(matriz[linha][coluna].nome) - 1);
        matriz[linha][coluna].nome[sizeof(matriz[linha][coluna].nome) - 1] = '\0';
        return 1; // sucesso
    }
    return 0; // falha
}

// método de cancelamento de reserva
void cancelarReserva(Mesa matriz[TAM][TAM], int linha, int coluna) {
    if (!matriz[linha][coluna].ocupada) {
        printf("A mesa [%d][%d] já está livre.\n", linha, coluna);
    } else {
        printf("Reserva de %s cancelada na mesa [%d][%d].\n", matriz[linha][coluna].nome, linha, coluna);
        matriz[linha][coluna].ocupada = 0;
        matriz[linha][coluna].status = 'L'; // volta pra livre
        matriz[linha][coluna].nome[0] = '\0';
    }
}

