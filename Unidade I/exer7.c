/*Escreva um programa em C que contém uma matriz N por N. O tamanho pode ser escolhido por você. Usando exclusivamente a aritmética de ponteiros, o programa deve percorrer e calcular o produto da diagonal principal, bem como produto da diagonal secundária.*/
#include <stdio.h>
#define TAM 3
void diagonal_principal(int matriz[TAM][TAM])
{
    int dp = 1;
    for (int linha = 0; linha < TAM; linha++)
    {
        for (int coluna = 0; coluna < TAM; coluna++)
        {
            if (linha == coluna)
            {
                dp *= *(*(matriz + linha) + coluna);
            }
        }
    }
    printf("Diagonal Principal: %d", dp);
}
void diagonal_secundaria(int matriz[TAM][TAM])
{
    int ds = 1;
    for (int i = 0; i < TAM; i++)
    {
        ds *= *(*(matriz + i) + (TAM - 1 - i));
    }

    printf("\nDiagonal Secundaria: %d", ds);
}
int main()
{
    int matriz[TAM][TAM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    diagonal_principal(matriz);
    diagonal_secundaria(matriz);
    return 0;
}