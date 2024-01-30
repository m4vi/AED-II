/*Crie um programa em C que utilize uma struct para armazenar informações sobre um produto em um sistema de inventário.

A struct deve conter o nome do produto, preço e quantidade em estoque.

O programa deve permitir ao usuário adicionar novos produtos ao sistema, atualizar a quantidade em estoque e o preço, listar todos os produtos com suas informações ou excluir um produto a partir do índice.

Além disso, implemente uma função para calcular o valor total em estoque de um produto, multiplicando o preço pela quantidade disponível.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    char nome[15];
    float preco;
    int quant_estoq;
} Produto;

void adicionar_produto(Produto *prod)
{
    printf("Digite o nome do produto: ");
    fflush(stdin);
    gets(prod->nome);
    printf("Digite o preco: ");
    scanf("%f", &prod->preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &prod->quant_estoq);
}

void atualizar_estoque(Produto p[], int *pos_aux)
{

    printf("Digite o novo preco: ");
    scanf("%f", &p[*pos_aux].preco);
    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &p[*pos_aux].quant_estoq);
}

float Calculo_Valor_Total(Produto *prod)
{
    float total;
    total = prod->preco*prod->quant_estoq;
    return total;
}

void listar_produtos(Produto p[], int *pos)
{
    printf("\nLista de produtos:\n");
    for (int i = 0; i < *pos; i++)
    {
        printf("%d. Nome: %s | Preco: %.2f | Quantidade em estoque:%d | Valor total em estoque: %.2f\n", i, p[i].nome, p[i].preco, p[i].quant_estoq, Calculo_Valor_Total(&p[i]));
    }
}

void excluir_produtos(Produto p[], int *pos, int *pos_exc)
{
    for (int i = *pos_exc; i < *pos - 1; i++)
    {
        p[i] = p[i + 1];
    }
    (*pos)--;
    printf("produto excluido com sucesso\n");
}

int main(void)
{
    int pos = 0;
    int opcao;
    do
    {
        Produto p[TAM];

        printf("-1 - sair\n");
        printf("1 - adicionar produto\n");
        printf("2 - atualizar a quantidade em estoque\n");
        printf("3 - listar produtos\n");
        printf("4 - excluir um produto a partir do indice\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        int pos_aux;
        switch (opcao)
        {
        case 1:
            if (pos < TAM)
            {
                adicionar_produto(&p[pos]);
                pos++;
            }
            else
            {
                printf("O inventario esta cheio\n");
            }
            break;
        case 2:
            if (pos != 0) // se o inventario tem algum item
            {
                printf("Qual posicao gostaria de atualizar? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    atualizar_estoque(p, &pos_aux);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O inventario esta vazio\n");
            }
            break;
        case 3:
            if (pos != 0)
            {
                listar_produtos(p, &pos);
            }
            else
            {
                printf("O inventario esta vazio\n");
            }
            break;
        case 4:
            if (pos != 0) // se o inventario tem algum item
            {
                printf("Qual posicao gostaria de excluir? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    excluir_produtos(p, &pos, &pos_aux);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O inventario esta vazio\n");
            }

            break;
        case -1:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != -1);

    return 0;
}

/*
void add (funcionario funcs[], int *pos)
{
    (*pos)++;
}

main funcionario f[10];
int posicao = 0;


scanf("%d", f[0].nome);

add();



*/

/*
void add (funcionario *f)

add(&f[pos]);
pos++;
*/

/*
para editar o nome
#include <string.h>

strcpy(f->nome,"jose");


*/