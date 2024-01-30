/*Implemente, na linguagem de 
programação C, um programa que
 contenha duas variáveis: uma do 
 tipo inteiro e outra com ponto 
 flutuante. Compare os endereços 
 dessas variáveis e exiba, de uma 
 só vez, o maior endereço de memória, 
junto ao valor que ele armazena. */

#include <stdio.h>
#include <stdlib.h>
void maior(int *inteiro, float *real)
{
    if (inteiro > real)
    {
        printf("%d", inteiro);
        printf("\nMaior endereço de memoria: %d, valor: %d", inteiro, *inteiro);
    }
    else if (inteiro < real)
    {
        printf("%f", real);
        printf("\nMaior endereço de memoria: %f, valor: %f", real, *real);
    }
}
int main()
{
    int num;
    float ponto_flutuante; // float é ponto flutuante

    printf("Digite o num inteiro: ");
    scanf("%d", &num);

    printf("Digite o num real: ");
    scanf("%f", &ponto_flutuante);

    maior(&num, &ponto_flutuante);
    return 0;
}