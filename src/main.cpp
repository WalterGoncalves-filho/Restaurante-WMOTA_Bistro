// src/main.c
#include <stdio.h>
#include <string.h>
#include "reservas.h"

int main() {
    Mesa restaurante[TAM][TAM];
    inicializarMesas(restaurante);

    // versao 1: setando as reservas manualmente!
    // reservarMesa(restaurante, 2, 3, "Ana");
    // reservarMesa(restaurante, 4, 4, "Walter");
    // exibirMesas(restaurante);
    // printf("\nO cliente %s reservou a mesa 2x3!", restaurante[2][3].nome);
    // printf("\nO cliente %s reservou a mesa 5x5!", restaurante[4][4].nome);

    


    exibirMesas(restaurante);
    // Simula reserva
    char nome[] = "Walter\0";

    printf("\n");

    // Cancela
    cancelarReserva(restaurante, 2, 3);

    return 0;
}
