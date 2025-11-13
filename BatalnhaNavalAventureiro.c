#include <stdio.h>

int main() {
    // Tabuleiro 10x10
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    int tamanhoNavio = 3;

    // Posições dos navios
    int linhaNavioHorizontal = 1;
    int colunaNavioHorizontal = 4;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;
    int linhaNavioDiagonal1 = 2;
    int colunaNavioDiagonal1 = 2;
    int linhaNavioDiagonal2 = 6;
    int colunaNavioDiagonal2 = 3;

    // Validando o posicionamento do navio horizontal
    if (colunaNavioHorizontal + tamanhoNavio - 1 >= 10) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validando o posicionamento do navio vertical
    if (linhaNavioVertical + tamanhoNavio - 1 >= 10) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // Validando o posicionamento do navio diagonal 1
    if (linhaNavioDiagonal1 + tamanhoNavio - 1 >= 10) {
        printf("Erro: Navio diagonal 1 fora dos limites!\n");
        return 1;
    }

    // Validando o posicionamento do navio diagonal 2
    if (linhaNavioDiagonal2 + tamanhoNavio - 1 >= 10 || colunaNavioDiagonal2 - (tamanhoNavio - 1) < 0) {
        printf("Erro: Navio diagonal 2 fora dos limites!\n");
        return 1;
    }

    // Garantindo que os navios não se sobreponham
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != 0) {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0) {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] != 0) {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] != 0) {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    }

    // Posicionando os navios
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = 3;
        tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = 3;
    }

    // Exibindo o tabuleiro
    printf("\n===Tabuleiro de Batalha Naval===\n");
    printf("   A B C D E F G H I J\n");  // Letras que representam as colunas do tabuleiro

    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            printf(" %d ", i + 1);
        } else {
            printf("%d ", i + 1);
        }

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
