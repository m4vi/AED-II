/*
Escreva, usando ponteiros, uma função que recebe duas variáveis do tipo inteiro: uma representa a idade de uma pessoa, enquanto a outra representa o sexo. A função deve atualizar o valor da variável que representa a idade para o tempo que falta para a pessoa se aposentar, considerando as seguintes regras hipotéticas:

mulheres podem se aposentar aos 60 anos;
homens podem se aposentar aos 65 anos;*/
#include <stdio.h>
#include <stdlib.h>
void aposentadoria(int *id, int *sex)
{
    if (*sex == 2) // se for mulher
    {
        *id = 60 - *id;
    }
    else if (*sex == 1) // se for homem
    {
        *id = 65 - *id;
    }
}
int main()
{
    int idade, sexo;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite o sexo (1: M / 2: F): ");
    scanf("%d", &sexo);

    printf("Idade: %d, sexo: %d", idade, sexo);

    aposentadoria(&idade, &sexo);

    printf("\nIdade: %d, sexo: %d", idade, sexo);

    return 0;
}