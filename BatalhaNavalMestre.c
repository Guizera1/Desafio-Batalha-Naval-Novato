#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM_HAB 5

int main() {
    // Tabuleiro 10x10
    int tabuleiro[LINHAS][COLUNAS];
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            tabuleiro[i][j] = 0;

    // Navio tamanho e posicao
    int tamanhoNavio = 3;
    int linhaNavioHorizontal = 0, colunaNavioHorizontal = 6;
    int linhaNavioVertical = 2, colunaNavioVertical = 9;
    int linhaNavioDiagonal1 = 0, colunaNavioDiagonal1 = 0;
    int linhaNavioDiagonal2 = 7, colunaNavioDiagonal2 = 9;

    // Limites dos navios
    if (colunaNavioHorizontal + tamanhoNavio - 1 >= COLUNAS) return 1;
    if (linhaNavioVertical + tamanhoNavio - 1 >= LINHAS) return 1;
    if (linhaNavioDiagonal1 + tamanhoNavio - 1 >= LINHAS) return 1;
    if (linhaNavioDiagonal2 + tamanhoNavio - 1 >= LINHAS || colunaNavioDiagonal2 - (tamanhoNavio - 1) < 0) return 1;

    // Validando sobreposição de navios
    for (int i = 0; i < tamanhoNavio; i++)
        if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != 0 ||
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0 ||
            tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] != 0 ||
            tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] != 0)
            return 1;

    // Posicao dos navios no tabuleiro
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = 3;
        tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = 3;
    }

    // Matrizes de habilidade
    int habilidadeCone[TAM_HAB][TAM_HAB], habilidadeCruz[TAM_HAB][TAM_HAB], habilidadeOctaedro[TAM_HAB][TAM_HAB];

    // Cone
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            if (i == 0 && j == 2) habilidadeCone[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3) habilidadeCone[i][j] = 1;
            else if (i == 2) habilidadeCone[i][j] = 1;
            else habilidadeCone[i][j] = 0;
    // Cruz
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            habilidadeCruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
    // Octaedro 
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            habilidadeOctaedro[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;

    // Posicao das habilidades
    int ConeLinha = 2, ConeColuna = 5;         // Cone (3,E)
    int CruzLinha = 5, CruzColuna = 2;         // Cruz (6,C)
    int OctaedroLinha = 7, OctaedroColuna = 7; // Octaedro (8,H)

    // Habilidades no tabuleiro
    // Cone
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++) {
            int linTab = ConeLinha - 2 + i;
            int colTab = ConeColuna - 2 + j;
            if (linTab >= 0 && linTab < LINHAS && colTab >= 0 && colTab < COLUNAS
                && habilidadeCone[i][j] == 1 && tabuleiro[linTab][colTab] != 3)
                tabuleiro[linTab][colTab] = 5;
        }
    // Cruz
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++) {
            int linTab = CruzLinha - 2 + i;
            int colTab = CruzColuna - 2 + j;
            if (linTab >= 0 && linTab < LINHAS && colTab >= 0 && colTab < COLUNAS
                && habilidadeCruz[i][j] == 1 && tabuleiro[linTab][colTab] != 3)
                tabuleiro[linTab][colTab] = 5;
        }
    // Octaedro
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++) {
            int linTab = OctaedroLinha - 2 + i;
            int colTab = OctaedroColuna - 2 + j;
            if (linTab >= 0 && linTab < LINHAS && colTab >= 0 && colTab < COLUNAS
                && habilidadeOctaedro[i][j] == 1 && tabuleiro[linTab][colTab] != 3)
                tabuleiro[linTab][colTab] = 5;
        }

    // Exibição do tabuleiro
    printf("=== Tabuleiro do Jogo Batalha Naval ===\n");
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < LINHAS; i++) {
        printf(i < 9 ? " %d " : "%d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) printf("~ "); // Alterado de 0 para ~ para melhorar visualização
            else if (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
            else printf("? ");
        }
        printf("\n");
    }
    return 0;
}
