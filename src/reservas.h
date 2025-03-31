// src/reserva.h
#ifndef RESERVA_H
#define RESERVA_H

#define TAM 30

// Estrutura de uma mesa
typedef struct {
    char nome[100];
    char status;
    int ocupada;
    int codigo;
} Mesa;

// Funções públicas do módulo
void inicializarMesas(Mesa matriz[TAM][TAM]);
void exibirMesas(Mesa matriz[TAM][TAM]);
void cancelarReserva(Mesa matriz[TAM][TAM], int linha, int coluna);
void cancelarReservaPorCodigo(Mesa matriz[TAM][TAM], int codigo);


int reservarMesa(Mesa matriz[TAM][TAM], int linha, int coluna, const char* nome);
int gerarCodigo();

#endif
