#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
   
    int tabuleiro[10][10] = {0}; // construção da matriz com todos os slots com 0
    int navio1_linha = 6, navio1_coluna = 7; // navio na horizontal
    int navio2_linha = 4, navio2_coluna = 5; // navio na vertical

    for( int i = 0; i < 3; i++) { // preenchimento dos slots vazios em 3 unidades no eixo x/y
        tabuleiro[navio1_linha + i][navio1_coluna] = 3; // navio na horizontal
        tabuleiro[navio2_linha][navio2_coluna + i] = 3; // navio na vertical
    }

    // saida do tabuleiro
    printf("Tabuleiro:\n"); 
    for(int x = 0; x < 10; x++) { // array para o eixo horizontal
        for(int y = 0; y < 10; y++) { // array para o eixo vertical
            printf("%d ", tabuleiro[x][y]); // saida de dados
        }
        printf("\n");
    }
    return 0;
}
