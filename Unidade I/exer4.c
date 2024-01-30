/*Crie um programa contendo dois vetores (A e B), de tamanho igual, cujos valores foram lidos do teclado. Em seguida, implemente uma função que recebe esses vetores e troque os valores do vetor A com os valores do vetor B. Use aritmética de ponteiros para efetuar essas operações. */
#include <stdio.h>
void troca(int *vetor1, int *vetor2)
{
    int aux[4];

    for (int i = 0; i < 4; i++)
    {
        aux[i] = *(vetor1 + i);
    }
    for (int i = 0; i < 4; i++)
    {
        *(vetor1 + i) = *(vetor2 + i);
    }
    for (int i = 0; i < 4; i++)
    {
        *(vetor2 + i) = aux[i];
    }
}

int main()
{
    int A[4], B[4];
    printf("Vamos preencher o vetor A. \n");
    for (int i = 0; i < 4; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &A[i]);
    }

    printf("Vamos preencher o vetor B. \n");
    for (int i = 0; i < 4; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &B[i]);
    }

    troca(A, B);

    printf("Vetor A\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\nVetor B\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", B[i]);
    }
    return 0;
}