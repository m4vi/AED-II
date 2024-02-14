#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char nome[30];

} Pessoa;

void cadastro(Pessoa *pessoinha)
{

    scanf("%d", &pessoinha->codigo);
    scanf("%s[\n]30", pessoinha->nome);
}

void imprimir(Pessoa *pessoinha)
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n%d", pessoinha->codigo);
    }
}

int main()
{
    int aux = 3;
    Pessoa *pessoinha = (Pessoa *)calloc(aux, sizeof(Pessoa));

    cadastro(pessoinha);

    imprimir(pessoinha);

    return 0;
}