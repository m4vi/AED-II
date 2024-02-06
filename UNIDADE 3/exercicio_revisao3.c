#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[15];
    int idade;
} Pessoa;

void cadastro(Pessoa *pessoinha)
{
    printf("Digite o nome: ");
    fflush(stdin);
    scanf("%s[\n]15", pessoinha->nome);
    printf("Digite a idade: ");
    scanf("%d", &pessoinha->idade);
}

void excluir(Pessoa Pessoinha[], int *pos, int *pos_exc)
{
    for (int i = *pos_exc; i < *pos - 1; i++)
    {
        Pessoinha[i] = Pessoinha[i + 1];
    }
    (*pos)--;
    printf("carro excluido com sucesso\n");
}

void listar(Pessoa pessoinha[], int *pos)
{
    for (int i = 0; i < *pos; i++)
    {
        printf("\nNome: %s, idade: %d ", pessoinha[i].nome, pessoinha[i].idade);
    }
}
int main()
{
    int n;
    printf("digite n: ");
    scanf("%d", &n);
    Pessoa *pessoinha = (Pessoa *)calloc(n, sizeof(Pessoa));
    int pos = 0, opc, pos_aux;

    do
    {
        printf("\n-1 - sair\n");
        printf(" 1 - cadastros\n");
        printf(" 2 - excluir\n");
        printf(" 3 - listar \n");
        printf(" Digite uma opcao: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:

            cadastro(&pessoinha[pos]);
            pos++;
            break;
        case 2:
            printf("digite a posicao q quer excluir: ");
            scanf("%d", &pos_aux);
            excluir(pessoinha, &pos, &pos_aux);
            break;
        case 3:
            listar(pessoinha, &pos);
            break;
        default:
            break;
        }

    } while (opc != -1);

    return 0;
}
