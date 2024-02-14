#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

void cadastro(Pessoa *pessoinha)
{
    printf("Nome: ");
    scanf("%s[\n]30", pessoinha->nome);
    printf("Idade: ");
    scanf("%d", &pessoinha->idade);
}

void excluir(Pessoa p[], int *n, int *aux)
{
    for (int i = *aux; i < *n - 1; i++)
    {
        p[i] = p[i + 1];
    }
    (*aux)--;
}

void listar(Pessoa p[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("\n nome: %s, idade: %d ", p[i].nome, p[i].idade);
    }
    
}
int main()
{
    int n, aux = 0;
    ;
    printf("digite n: ");
    scanf("%d", &n);

    Pessoa *pessoinha = (Pessoa *)calloc(n, sizeof(Pessoa));

    cadastro(&pessoinha[aux]);

    listar(pessoinha, &n);

    excluir(pessoinha, &n, &aux);

    listar(pessoinha, &n);

    return 0;
}