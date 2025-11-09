/*
    Desafio Mestre - Bathalna Naval
    Autor: Rodrigo Roither
    Data: 09/11/2025
    Descrição: Implementação do tabuleiro de batalha naval com habilidades especiais e colocação de navios.
*/
#include <stdio.h>

#define LINHAS 10
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

    //==================================== Habilidade Cone ====================================
    int cone_linha_inicial = 0; // Linha 1 -> índice 0
    int cone_coluna_inicia = 4; // Coluna 'E' -> índice 4
    int altura_cone = 3;        // Cone de 3 linhas de altura

    // Loop para cada linha da altura do cone
    for (i = 0; i < altura_cone; i++) {

        // Loop para as colunas dessa linha específica
        // Começa em (coluna_inicial - alcance) e vai até (coluna_inicial + alcance)
        for (j = cone_coluna_inicia - i; j <= cone_coluna_inicia + i; j++) {

            // Define as coordenadas atuais que vamos pintar
            int linha_atual = cone_linha_inicial + i;
            int coluna_atual = j;

            // Validação: Checa se estamos DENTRO dos limites do tabuleiro
            if (linha_atual >= 0 && linha_atual < LINHAS &&
                coluna_atual >= 0 && coluna_atual < COLUNAS) {

                // Se for válido, preenche o tabuleiro
                tabuleiro[linha_atual][coluna_atual] = 5;
            }
        }
    }

    //==================================== Habilidade Cruz ====================================
    int cruz_linha_centro = 7;
    int cruz_coluna_centro = 6;
    int cruz_raio_vertical = 1;   // 1 para cima/baixo (total 3 de altura)
    int cruz_raio_horizontal = 2; // 2 para esq/dir (total 5 de largura)

    // Pinta a Barra Horizontal
    for (j = cruz_coluna_centro - cruz_raio_horizontal; j <= cruz_coluna_centro + cruz_raio_horizontal; j++) {
        int linha_atual = cruz_linha_centro;
        int coluna_atual = j;

        // Validação de limites
        if (linha_atual >= 0 && linha_atual < LINHAS &&
            coluna_atual >= 0 && coluna_atual < COLUNAS) {

            tabuleiro[linha_atual][coluna_atual] = 5;
        }
    }

    // Pinta a Barra Vertical
    for (i = cruz_linha_centro - cruz_raio_vertical; i <= cruz_linha_centro + cruz_raio_vertical; i++) {
        int linha_atual = i;
        int coluna_atual = cruz_coluna_centro;

        // Validação de limites
        if (linha_atual >= 0 && linha_atual < LINHAS &&
            coluna_atual >= 0 && coluna_atual < COLUNAS) {

            tabuleiro[linha_atual][coluna_atual] = 5;
        }
    }

    //==================================== Habilidade Octaedro (Losango) ====================================
    int octa_linha_centro = 4;
    int octa_coluna_centro = 7;
    int octa_raio = 1; // Raio 1 = 3 de altura (1-3-1) | Raio 2 = 5 de altura (1-3-5-3-1)

    // Loop pelas linhas da forma (de -raio a +raio em relação ao centro)
    for (i = -octa_raio; i <= octa_raio; i++) {
        int linha_atual = octa_linha_centro + i;

        // Calcula o raio horizontal para esta linha específica
        int i_absoluto = (i < 0) ? -i : i;
        int raio_horizontal = octa_raio - i_absoluto;

        // Loop pelas colunas da forma (de -raio_horizontal a +raio_horizontal em relação ao centro)
        for (j = -raio_horizontal; j <= raio_horizontal; j++) {
            int coluna_atual = octa_coluna_centro + j;

            // Validação de limites
            if (linha_atual >= 0 && linha_atual < LINHAS &&
                coluna_atual >= 0 && coluna_atual < COLUNAS) {

                tabuleiro[linha_atual][coluna_atual] = 5;
            }
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
        if (navio1_col_inicial + j >= COLUNAS) {
            valido = 0;
            break;
        }
        // Validação de sobreposição (AGORA CHECA SE TEM ÁGUA '0')
        if (tabuleiro[navio1_linha][navio1_col_inicial + j] != 0) {
            valido = 0;
            break;
        }
    }

    //Colocando o Navio 1 (Horizontal)
    if (valido) {
        for (j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[navio1_linha][navio1_col_inicial + j] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 1 é inválida! (Sobrepondo ou fora do limite)\n");
    }

    //==================================== Segundo Navio (Vertical) ====================================

    //variáveis do navio 2 onde começará o posicionamento
    int navio2_linha_inicial = 7; // Linha 8 -> índice 7
    int navio2_coluna = 9;        // Coluna 'J' -> índice 9

    //variável de validação que por padrão é 1
    valido = 1; // Reutiliza a variável, resetando para 1

    // Loop de Validação
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Validação de limites (se sai da linha 9)
        if (navio2_linha_inicial + i >= LINHAS) {
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
    if (valido) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha_inicial + i][navio2_coluna] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 2 é inválida! (Sobrepondo ou fora do limite)\n");
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
        printf("Erro: Posição do Navio 3 é inválida! (Sobrepondo ou fora do limite)\n");
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
        printf("Erro: Posição do Navio 4 é inválida! (Sobrepondo ou fora do limite)\n");
    }

    //==================================== Imprimindo o tabuleiro na tela ====================================
    printf("### TABULEIRO BATALHA NAVAL ###\n\n");
    printf("  A B C D E F G H I J\n"); // Ajustei o espaçamento para alinhar
    // Loop aninhado para imprimir o estado final da matriz
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Imprime o número da linha com 2 dígitos
        for (j = 0; j < 10; j++) {
            // Imprime o caractere correspondente
            switch (tabuleiro[i][j]) {
            case 0: // Água
                printf("0 ");
                break;
            case 3: // Navio
                printf("3 ");
                break;
            case 5: // Habilidade
                printf("5 ");
                break;
            default: // Outro (caso exista)
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}