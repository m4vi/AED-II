/*Crie um programa contendo três vetores (A, B e C), de tamanho igual. Para os vetores A e B, os valores devem ser lidos do teclado. 

Em seguida, implemente uma função que recebe os três vetores. Cada posição do vetor C deve ser preenchido com o maior valor do vetor A ou B naquela mesma posição.

Use aritmética de ponteiros para efetuar essas operações. */

#include <stdio.h>
void Maior(int *A, int *B, int *C)
{
    for (int i = 0; i < 3; i++)
    {
        if (*(A+i) > *(B+i))
        {
            *(C+i)=*(A+i);
        }
        else
        {
            *(C+i) = *(B+i);
        }

    }
    
}
int main()
{
    int A[3], B[3], C[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o valor do vetor A na posicao %d: ", i);
        scanf("%d", A+i);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o valor do vetor B na posicao %d: ", i);
        scanf("%d", B+i);
    }

    Maior(A, B, C);
    printf("Exibição C:  ");
    for (int i = 0; i < 3; i++)
    {
        printf("\nPosicao %d: Valor: %d ", i, *(C+i));
    }

    
    return 0;
}