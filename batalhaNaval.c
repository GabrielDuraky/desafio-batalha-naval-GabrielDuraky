#include <stdio.h>
// coodernadas habilidade cruz (2, 3), matriz [3][3]
// coodernadas octaedro 
#define TABULEIRO_LINHAS 10
#define TABULEIRO_COLUNAS 10


void habilidade(int tabuleiro[TABULEIRO_LINHAS][TABULEIRO_COLUNAS], 
     int habilidade_matriz[3][5], int linha_inicio, int coluna_inicio) { // declaração das variaveis da função
        for(int i = 0; i < 3; i++) { // for para linhas da habilidade_matriz
            for(int j = 0; j < 5; j++) { // for para colunas da habiliade_matriz
                if (habilidade_matriz[i][j] != 0) { // verifica se o valor do indice não é zero
                    int tabuleiro_linha = linha_inicio + i;
                    int tabuleiro_coluna = coluna_inicio + j;
                    if (tabuleiro_linha < TABULEIRO_LINHAS && tabuleiro_coluna < TABULEIRO_COLUNAS) {
                        if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0) {
                            tabuleiro[tabuleiro_linha][tabuleiro_coluna] = habilidade_matriz[i][j];
                        }
                    }
                }
            }
        }
     }

int main() {
   
    int tabuleiro[TABULEIRO_LINHAS][TABULEIRO_COLUNAS] = {0}; // construção da matriz com todos os slots com 0
    int navio1_linha = 6, navio1_coluna = 8; // navio na vertical
    int navio2_linha = 4, navio2_coluna = 5; // navio na horizontal
    int navio3_linha = 1, navio3_coluna = 6; // navio na diagonal vetor baixo/direita
    int navio4_linha = 8, navio4_coluna = 2; // navio na diagonal vetor cima/ direita
    int cruz[3][5] = {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0}};
    int octaedro[3][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}};
    int cone[3][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}};

    for(int i = 0; i < 3; i++) { // preenchimento dos slots vazios em 3 unidades no eixo x/y
        tabuleiro[navio1_linha + i][navio1_coluna] = 3; // navio vertical
        tabuleiro[navio2_linha][navio2_coluna + i] = 3; // navio na horizontal
        tabuleiro[navio3_linha + i][navio3_coluna + i] = 3; // navio diagonal para baixo/direita
        tabuleiro[navio4_linha - i][navio4_coluna + i] = 3; // navio  diagonal para cima/direita
    }

    habilidade(tabuleiro, cruz, 0, 1); // 
    habilidade(tabuleiro, octaedro, 4, 0);
    habilidade(tabuleiro, cone, 6, 3);

    

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
