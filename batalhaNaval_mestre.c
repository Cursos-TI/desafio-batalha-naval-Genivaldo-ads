#include <stdio.h>
#include <stdlib.h> // Necessário para usar a função abs()

#define TAM 10

// Função: imprime o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função: habilidade em forma de CONE
// Marca posições em formato de triângulo para baixo
void habilidadeCone(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {           // altura do cone
        for (int j = -i; j <= i; j++) {     // largura varia conforme i
            if (linha + i < TAM && coluna + j >= 0 && coluna + j < TAM) {
                tabuleiro[linha + i][coluna + j] = '3'; // marca o ataque
            }
        }
    }
}

// Função: habilidade em forma de CRUZ
// Marca uma cruz com 5 posições em cada braço
void habilidadeCruz(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        if (linha + i >= 0 && linha + i < TAM)
            tabuleiro[linha + i][coluna] = '3'; // vertical

        if (coluna + i >= 0 && coluna + i < TAM)
            tabuleiro[linha][coluna + i] = '3'; // horizontal
    }
}

// Função: habilidade em forma de OCTAEDRO
// Usa valor absoluto para desenhar um losango de raio 2
void habilidadeOctaedro(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (linha + i >= 0 && linha + i < TAM && coluna + j >= 0 && coluna + j < TAM) {
                if (abs(i) + abs(j) <= 2) // forma de losango (ou octaedro 2D)
                    tabuleiro[linha + i][coluna + j] = '3';
            }
        }
    }
}

// Função principal
int main() {
    char tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    printf("=== Batalha Naval - Nivel Mestre ===\n\n");

    // Aplicando as habilidades em diferentes posições
    habilidadeCone(tabuleiro, 0, 3);
    habilidadeCruz(tabuleiro, 4, 5);
    habilidadeOctaedro(tabuleiro, 7, 7);

    // Exibe o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
