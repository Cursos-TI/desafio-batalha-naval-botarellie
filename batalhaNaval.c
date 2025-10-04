#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    
    // Nível Novato - Posicionamento dos Navios

    // Declaração das variáveis
    int tabuleiro[10][10];
    int i, j;

    printf("=====JOGO BATALHA NAVAL (Nível Novato)======\n");
    printf("\n");

    // Inicializar tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (tamanho 3)
    int linha1 = 2, coluna1 = 4;
    tabuleiro[linha1][coluna1] = 3;
    tabuleiro[linha1][coluna1 + 1] = 3;
    tabuleiro[linha1][coluna1 + 2] = 3;

    // Navio vertical (tamanho 3)
    int linha2 = 5, coluna2 = 7;
    tabuleiro[linha2][coluna2] = 3;
    tabuleiro[linha2 + 1][coluna2] = 3;
    tabuleiro[linha2 + 2][coluna2] = 3;

    // Mostrar o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    
    printf("\n =====JOGO BATALHA NAVAL (Nível Aventureiro)======\n");
    printf("\n");

    //int i, j;

    // Posições iniciais dos navios
    int linhaH = 2, colunaH = 4;   // horizontal
    int linhaV = 5, colunaV = 7;   // vertical
    int linhaD1 = 1, colunaD1 = 1; // diagonal ↘
    int linhaD2 = 6, colunaD2 = 6; // diagonal ↙

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {

            // Cada expressão vale 1 se for navio, 0 se não for
            int horizontal = (i == linhaH && (j == colunaH || j == colunaH + 1 || j == colunaH + 2));
            int vertical   = (j == colunaV && (i == linhaV || i == linhaV + 1 || i == linhaV + 2));
            int diagonal1  = ((i == linhaD1 && j == colunaD1) ||
                              (i == linhaD1 + 1 && j == colunaD1 + 1) ||
                              (i == linhaD1 + 2 && j == colunaD1 + 2));
            int diagonal2  = ((i == linhaD2 && j == colunaD2) ||
                              (i == linhaD2 + 1 && j == colunaD2 - 1) ||
                              (i == linhaD2 + 2 && j == colunaD2 - 2));

            // Se alguma condição for verdadeira imprime 3, senão imprime 0
            printf("%d ", 3 * (horizontal || vertical || diagonal1 || diagonal2));
        }
        printf("\n");
    }


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    printf("\n =====JOGO BATALHA NAVAL (Nível Mestre)======\n");
    printf("\n");
 
    //int i, j;

    // Cone (3x5)
    int cone[3][5] = {0};
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 0 && j == 2) cone[i][j] = 1;           // topo
            if (i == 1 && (j == 1 || j == 2 || j == 3))     // meio
                cone[i][j] = 1;
            if (i == 2) cone[i][j] = 1;                     // base cheia
        }
    }

    // Cruz (3x5)
    int cruz[3][5] = {0};
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 1 || j == 2) { // linha central e coluna central
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (3x5)
    int octa[3][5] = {0};
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) ||
                (i == 1 && (j == 1 || j == 3)) ||
                (i == 2 && j == 2)) {
                octa[i][j] = 1;
            }
        }
    }

    // Exibir Cone
    printf("Cone:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    // Exibir Cruz
    printf("\nCruz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    // Exibir Octaedro
    printf("\nOctaedro:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", octa[i][j]);
        }
        printf("\n");
    }



    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
