// src/reserva.h
#ifndef RESERVA_H
#define RESERVA_H

#define TAM 5

// Estrutura de uma mesa
typedef struct {
    char status;
    int ocupada;
    char nome[100];
} Mesa;

// Funções públicas do módulo
void inicializarMesas(Mesa matriz[TAM][TAM]);
void exibirMesas(Mesa matriz[TAM][TAM]);
int reservarMesa(Mesa matriz[TAM][TAM], int linha, int coluna, const char* nome);
void cancelarReserva(Mesa matriz[TAM][TAM], int linha, int coluna);

#endif
