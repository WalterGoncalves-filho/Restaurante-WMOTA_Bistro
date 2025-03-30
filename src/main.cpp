// src/main.c
#include "imports.h"
#include "reservas.h"

Mesa restaurante[TAM][TAM];
void iniciarSistema();

int main() {


    // menu do usuario:
    printf("\n======================================\n");
    printf("+    Restaurante do WMota Bistro     +\n");
    printf("======================================\n");

    iniciarSistema();

    return 0;
}

void iniciarSistema(){
    
    inicializarMesas(restaurante);

    int op;
    do{
        printf("\n");
        printf("\n----- Menu -----\n\n");
        printf("[1] Reservar mesa\n");
        printf("[2] Cancelar reserva\n");
        printf("[3] Exibir mesas\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        int linha, coluna;
        char nome[50];

    switch (op){
    case 1: 
        printf("Linha: ");
            scanf("%d", &linha);
        printf("Coluna: ");
            scanf("%d", &coluna);
        printf("Nome: ");
            scanf(" %49[^\n]", nome);
        if (reservarMesa(restaurante, linha, coluna, nome))
            printf("Reserva realizada com sucesso.\n");
        else
            printf("Não foi possível reservar a mesa.\n");
        break;
    
    case 2:  
        printf("Linha da mesa a cancelar: ");
        scanf("%d", &linha);
        printf("Coluna da mesa a cancelar: ");
        scanf("%d", &coluna);
        cancelarReserva(restaurante, linha, coluna);
        break;

    case 3: 
        system("cls");
        exibirMesas(restaurante);  
        break;

    default: printf("Saindo...\n");
        break;
    }

    }while (op!=0);


}