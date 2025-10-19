#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro (10x10)

int main() {
    char tabuleiro[TAM][TAM];

    // Inicia o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Navio horizontal de tamanho 3 na linha 2
    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = '7';  //navio representa o numero 7
    }

    // Navio vertical de tamanho 3 na coluna 5
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][5] = '7';  //navio representa o numero 7
    }

    // Mostra o tabuleiro
    printf("Batalha Naval - Nivel Novato\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0; //fim do programa
}
