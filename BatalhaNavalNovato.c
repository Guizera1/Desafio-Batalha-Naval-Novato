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
    int colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

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

    // Posicionando os navios
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }

    // Exibindo o tabuleiro
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