#include <stdio.h>

#define LINHAS  10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main() {

    int i, j;
    int tabuleiro[LINHAS][COLUNAS];

    // Limpando o Tabuleiro (Enchendo de Água)
    for (i = 0; i < LINHAS; i++) { // Loop externo para percorrer cada linha
        for (j = 0; j < COLUNAS; j++) { // Loop interno para percorrer cada coluna
            tabuleiro[i][j] = 0; // Define o valor de cada célula como água (0)
        }
    }

    //==================================== Primeiro Navio (Horizontal) ====================================

    //variáveis do navio 1 onde começará o posicionamento
    int navio1_linha = 0;       // Linha 1 -> índice 0
    int navio1_col_inicial = 0; // Coluna 'A' -> índice 0

    //variável de validação que por padrão é 1
    int valido = 1;

    // Loop de Validação
    for (j = 0; j < TAMANHO_NAVIO; j++) // loop externo
    {
        // Validação de limites (se sai da coluna 9)
        if (navio1_col_inicial + j >= COLUNAS) 
        {
            valido = 0;
            break;
        }
        // Validação de sobreposição 
        if (tabuleiro[navio1_linha][navio1_col_inicial + j] != 0) {
            valido = 0;
            break;
        }
    } 
    

    //Colocando o Navio 1 (Horizontal)
    if (valido)
    {
        for (j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[navio1_linha][navio1_col_inicial + j] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 1 é inválida!\n");
    }
    

    //==================================== Segundo Navio (Vertical) ====================================

    //variáveis do navio 2 onde começará o posicionamento
    int navio2_linha_inicial = 7; // Linha 8 -> índice 7
    int navio2_coluna = 9;        // Coluna 'J' -> índice 9

    //variável de validação que por padrão é 1
    valido = 1; // Reutiliza a variável, resetando para 1

    
    // Loop de Validação
    for (i = 0; i < TAMANHO_NAVIO; i++)
    {
        // Validação de limites (se sai da linha 9)
        if (navio2_linha_inicial + i >= LINHAS)
        {
            valido = 0;
            break;
        }
        // Validação de sobreposição 
        if (tabuleiro[navio2_linha_inicial + i][navio2_coluna] != 0) {
            valido = 0;
            break;
        }
    } 

    //Colocando o Navio 2 (Vertical)
    if (valido)
    {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha_inicial + i][navio2_coluna] = 3;
        } 
    }else {
        printf("Erro: Posição do Navio 2 é inválida!\n");
    }

    //==================================== Terceiro Navio (Diagonal \ ) ====================================

    //variáveis do navio 3 onde começará o posicionamento
    int navio3_linha_inicial = 3; // Linha 4 -> índice 3
    int navio3_coluna = 3;        // Coluna 'D' -> índice 3

    valido = 1; // Reseta a validação

    //Loop de validação
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Valida se sai dos limites de linha OU coluna
        if (navio3_linha_inicial + i >= LINHAS || navio3_coluna + i >= COLUNAS) {
            valido = 0;
            break;
        }
        // Valida sobreposição
        if (tabuleiro[navio3_linha_inicial + i][navio3_coluna + i] != 0) {
            valido = 0;
            break;
        }
    }

    //Colocando o Navio 3 (Diagonal)
    if (valido) {
        for (i = 0; i < 3; i++) {
            tabuleiro[navio3_linha_inicial + i][navio3_coluna + i] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 3 é inválida!\n");
    }


    //==================================== Quarto Navio (Diagonal / ) ====================================

    //variáveis do navio 4 onde começará o posicionamento
    int navio4_linha_inicial = 7; // Linha 8 -> índice 7
    int navio4_coluna = 3;        // Coluna 'D' -> índice 3

    valido = 1; // Reseta a validação

    // ADICIONADO: Loop de validação para diagonal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Valida se sai dos limites de linha (>= LINHAS) OU coluna (< 0)
        if (navio4_linha_inicial + i >= LINHAS || navio4_coluna - i < 0) {
            valido = 0;
            break;
        }
        // Valida sobreposição
        if (tabuleiro[navio4_linha_inicial + i][navio4_coluna - i] != 0) {
            valido = 0;
            break;
        }
    }


    //Colocando o Navio 4 (Diagonal)
    if (valido) {
        for (i = 0; i < 3; i++) {
            // CORREÇÃO: A coluna deve diminuir (navio4_coluna - i)
            tabuleiro[navio4_linha_inicial + i][navio4_coluna - i] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 4 é inválida!\n");
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