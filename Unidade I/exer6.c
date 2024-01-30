/*Escreva um programa com um vetor de tamanho N (informado pelo usuário via teclado), com dados de tipo inteiro ou ponto flutuante (a seu critério), também informados pelo usuário final via teclado. 

Em seguida, implemente uma função que receba esse vetor e crie uma matriz de tamanho N por N. A primeira coluna da matriz deve conter os valores originais do vetor. As colunas restantes devem conter o resultado da multiplicação por 2, 3… n-1.

Exemplo:

Considere o seguinte vetor de entrada:
1	2	3	4	5


Considere a matriz de saída:

1	2	3	4	5
2	4	6	8	10
3	6	9	12	15
4	8	12	16	20
5	10	15	20	25


Elabore as operações usando exclusivamente aritmética de ponteiros para percorrer o vetor e a matriz.*/

#include <stdio.h>
void Matriz(int *vet, int tam)
{
    int matriz[tam][tam];

    for (int linha = 0; linha < tam; linha++)
    {
        for (int coluna = 0; coluna < tam; coluna++)
        {
           *( * (matriz + linha) + coluna) = (*(vet + coluna)) * (*(vet + linha));
        }
    }

    printf("Matriz: \n");

    for (int linha = 0; linha < tam; linha++)
    {
        for (int coluna = 0; coluna < tam; coluna++)
        {
            printf("%d\t",  *( * (matriz + linha) + coluna));
        }
        printf("\n");
    }
}

int main()
{
    int tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor[tam];

    for (int i = 0; i < tam; i++)
    {
        printf("Digite o valor do vetor na posicao %d: ", i);
        scanf("%d", vetor + i);
    }

    Matriz(vetor, tam);

    return 0;
}