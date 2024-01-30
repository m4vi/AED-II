
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
    gets(Est->dep->nome);

    int flag = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(d[i].nome, Est->dep->nome) == 0) // se exister um dep igual só atribui
        {
            Est->dep = &d[i];
            flag = 1;
            break;
        }
    }
    if ((*pos_dep < 5) && (flag = 1))
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
}

void listar(funcionario f[], int *pos)
{
    for (int i = 0; i < *pos; i++)
    {
        printf("\nNome: %s, codigo: %d, departamento: %s, dep cod: %d", f[i].nome, f[i].codigo, f[i].dep->nome, f[i].dep->codigo);
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
    printf("4 - departamento codigo\n");
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
        (f[pos_aux].dep) = &(d[pos_aux2]);
        break;
    default:
        break;
    }
}
int main(void)
{
    int pos_fun = 0, pos_dep = 0;
    int opcao;
    departamento d[TAM];
    funcionario f[TAM];
    do
    {

        printf("\n-1 - sair\n");
        printf(" 1 - cadastros\n");
        printf(" 2 - Atualizar\n");
        printf(" 3 - listar \n");
        printf(" Digite uma opcao: ");
        scanf("%d", &opcao);

        // int pos_aux;
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
                printf("esta cheio\n");
            }
            break;
        case 2:
            atualizar(f, &pos_fun, d, &pos_dep);
            break;
        case 3:
            if (pos_fun != 0)
            {
                listar(f, &pos_fun);
            }
            else
            {
                printf("esta vazio\n");
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