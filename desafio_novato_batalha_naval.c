#include <stdio.h>

int main() {

int i, j;

int tabuleiro[10][10];


// Limpando o Tabuleiro (Enchendo de Água)
for (i = 0; i < 10; i++) { // Loop externo para percorrer cada linha
        for (j = 0; j < 10; j++) { // Loop interni para percorrer cada coluna
            tabuleiro[i][j] = 0; // Define o valor de cada célula como água (0)
        }
    }

//==================================== Primeiro Navio ====================================

    //variáveis do navio 1 onde começará o posicionamento
    int navio1_linha = 2;       // Linha 3 -> índice 2 (porque 0, 1, 2)
    int navio1_col_inicial = 3; // Coluna 'D' -> índice 3 (A=0, B=1, C=2, D=3)

    //Colocando o Navio 1 (Horizontal)
    for (j = 0; j < 3; j++) {
        tabuleiro[navio1_linha][navio1_col_inicial + j] = 3;
    }


//==================================== Segundo Navio ====================================

    //variáveis do navio 2 onde começará o posicionamento
    int navio2_linha_inicial = 5; // Linha 6 -> índice 5
    int navio2_coluna = 7;        // Coluna 'H' -> índice 7 (A=0 ... H=7)

    //Colocando o Navio 2 (Vertical)
     for (i = 0; i < 3; i++) {
        tabuleiro[navio2_linha_inicial + i][navio2_coluna] = 3;
    }


//==================================== Imprimindo na tela o tabuleiro ====================================

     printf("### TABULEIRO BATALHA NAVAL ###\n\n");
    
    // Imprimindo o cabeçalho de colunas 'A' até 'J'
    printf("   A B C D E F G H I J\n"); 
    
    // Loop aninhado para imprimir o estado final da matriz
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}