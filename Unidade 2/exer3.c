
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct
{
    char nome[12];
    int codigo;
} departamento;

typedef struct
{
    char nome[12];
    int codigo;
    departamento *dep;
} funcionario;

void cadastro(funcionario *Est, departamento d[], int *pos_dep)
{
    printf("Digite o nome: ");
    fflush(stdin);
    gets(Est->nome);
    printf("Digite o codigo ");

    scanf("%d", &Est->codigo);

    printf("Digite departamento: ");
    fflush(stdin);
    // gets(Est->dep.nome);

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(d[i].nome, gets((Est->dep->nome)) == 0)) // se exister um dep igual só atribui
        {
            *(Est->dep) = d[i];
            break;
        }
        else // se nao cria o dep
        {
            if (*pos_dep < 5)
            {
                printf("digite nome do dep: ");
                fflush(stdin);
                gets(d[*pos_dep].nome);

                printf("digite codigo do dep: ");
                scanf("%d", &d[*pos_dep].codigo);
                (*pos_dep)++;
            }
            else
            {
                printf("departamentos maximo");
            }
            break;
        }
    }
}

void listar(funcionario f[], int *pos)
{
    for (int i = 0; i < *pos; i++)
    {
        printf("\nNome: %s, codigo: %d, departamento: %s, dep cod: %d", f[i].nome, f[i].codigo, f[i]->dep.nome, f[i]->dep.codigo);
    }
}
void listar_D(departamento f[], int *pos)
{
    for (int i = 0; i < *pos; i++)
    {
        printf("\n departamento: %s, dep cod: %d", f[i].nome, f[i].codigo);
    }
}

void atualizar(funcionario f[], int *pos, departamento d[], int *pos_dep)
{
    int opc;

    printf("1 - nome\n");
    printf("2 - codigo nome \n");
    printf("3 - departamento nome\n");
    printf("4 - departamento coigo\n");
    printf("5 - departamento de um funcionario\n");
    printf("O que deseja atualizar: ");
    scanf("%d", &opc);

    switch (opc)
    {
    int pos_aux, pos_aux2;
    case 1:
        listar(f, pos);
        printf("digite a posicao ");
        scanf("%d", &pos_aux);
        printf("Digite o nome: ");
        fflush(stdin);
        gets(f[pos_aux].nome);
        break;
    case 2: 
        listar(f, pos);
        
        printf("digite a posicao ");
        scanf("%d", &pos_aux);
        printf("Digite o codigo: ");
        fflush(stdin);
        scanf("%d", &f[pos_aux].codigo);
        break;
    case 3:
        listar_D(d, pos_dep);
        printf("digite a posicao ");
        scanf("%d", &pos_aux);
        printf("Digite o nome: ");
        fflush(stdin);
        gets(d[pos_aux].nome);
        break;
    case 4:
        listar_D(d, pos_dep);
        printf("digite a posicao ");
        scanf("%d", &pos_aux);
        printf("Digite o codigo: ");
        fflush(stdin);
        scanf("%d", &d[pos_aux].codigo);
        break;
    case 5: 
        listar(f, pos);
        printf("digite a posicao do funcionario"); // POSICAO DO VETOR F
        scanf("%d", &pos_aux);
        listar_D(d, pos_dep);
        printf("Digite a posicao do departamento que vc quer mandar o funcionario: "); // POSICAO VETOR D
        scanf("%d", &pos_aux2);
        (f[pos_aux].dep) = d[pos_aux2];
        break;
    default:
        break;
    }
}
int main(void)
{
    int pos_fun = 0, pos_dep = 0;
    int opcao;
    do
    {
        departamento d[TAM];
        funcionario f[TAM];

        printf("\n-1 - sair\n");
        printf("1 - cadastros\n");
        printf("2 - Custo do estacionamento pelas horas estacionadas (tarifa R$10,00 p/ hr)\n");
        printf("3 - Registrar a saida dos veiculos\n");
        printf("4 - Listagem de veiculos\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        int pos_aux;
        switch (opcao)
        {
        case 1:
            if (pos_fun < TAM)
            {
                cadastro(&f[pos_fun], d, &pos_dep);
                pos_fun++;
            }
            else
            {
                printf("O estacionamento esta cheio\n");
            }
            break;
        case 2:
            atualizar(f, &pos_fun, d, &pos_dep);
            break;
        /*case 2:
            if (pos != 0) // se o inventario tem algum item
            {
                printf("Qual posicao gostaria de calcular o custo do estacionamento? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    calculo_custo(&e[pos_aux]);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O estacionamento esta vazio\n");
            }
            break;
        case 3:
            if (pos != 0) // se o est tem algum item
            {
                printf("Qual carro ira sair? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    saida_carro(e, &pos, &pos_aux);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O estacionamento esta vazio\n");
            }

            break;
        */
        case 4:
            if (pos_fun != 0)
            {
                listar(f, &pos_fun);
            }
            else
            {
                printf("O estacionamento esta vazio\n");
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