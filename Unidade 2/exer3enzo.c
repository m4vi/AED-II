#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    char nome[16];
    int codigo;
} departamento;

typedef struct
{
    char nome[30];
    int codigo;
    departamento dep;
} funcionario;

void preencher_departamento(departamento *d)
{
    getchar(); // pega o caracter enter que veio do main q se perderia dps dp enter. Coloquei pq teve um scanf do medo
    printf("Departamento: \n");
    printf("Digite o nome: ");
    fgets(d->nome, sizeof(d->nome), stdin); // a diferenca é q fgets pq le arquivo, o gets le direto do teclado
    printf("Digite o codigo do departamento: ");
    scanf("%d", &d->codigo);

    /*
    ->nome acessa a informacao de uma struc passada como ponteiro
    .nome acessa a informacao de uma struc comum
    */
}

void preencher_funcionario(funcionario *f)
{
    getchar(); // pega o caracter enter que veio do main q se perderia dps dp enter. Coloquei pq teve um scanf do medo
    printf("FUNCIONARIO: \n");
    printf("Digite o nome: ");
    fgets(f->nome, sizeof(f->nome), stdin); // a diferenca é q fgets pq le arquivo, o gets le direto do teclado
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &f->codigo);

    preencher_departamento(&f->dep);

    printf("Digite o nome do departamento: ");
    fgets(f->dep.nome, sizeof(f->dep.nome), stdin);
    printf("Digite o codigo do departamento: ");
    scanf("%d", &f->dep.codigo);

    
    /*
    ->nome acessa a informacao de uma struc passada como ponteiro
    .nome acessa a informacao de uma struc comum
    */
}


void cadastrar_funcionario(funcionario f[], int *pos)
{
    if (*pos < TAM)
    {
        preencher_funcionario(&f[*pos]); // passo o funcionario na posicao correta
        (*pos)++;
    }
    else
    {
        printf("Cheio!\n");
    }
}

void atualizar(funcionario f[], int *pos, int posEdit)
{
    if (posEdit < *pos)
    {
        preencher(&f[posEdit]);
    }
    else
    {
        printf("Invalido");
    }
}

void excluir(funcionario f[], int *pos, int pos_exc)
{
    if (pos_exc < *pos)
    {
        for (int i = pos_exc; i < *pos - 1; i++)
        {
            f[i] = f[i + 1];
        }
        (*pos)--;
        printf("funcionario excluido com sucesso");
    }
    else
    {
        printf("Invalido\n");
    }
}

void imprimir(funcionario f[], int pos)
{
    for (int i = 0; i < pos; i++)
    {
        printf("Nome: %s\n", f[i].nome);
        printf("Codigo: %s\n", f[i].codigo);
        //printf("Salario: %f\n", f[i].salario);
    }
}
int main(void)
{
    funcionario f[TAM];
    departamento d[TAM];
    int pos = 0;

    int opc;
    int aux;

    do
    {
        printf("\nopcoes\n");
        printf(" 1 - cadastrar\n");
        printf(" 2 - atualizar\n");
        printf(" 3 - listar\n");
        printf(" 4 - excluir\n");
        printf("-1 - sair\n");

        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastrar_funcionario(f, &pos_func);
            break;
        case 2:
            printf("Digite a posicao q quer atualizar: ");
            scanf("%d", &aux);
            atualizar(f, &pos, aux);
            break;
        case 3:
            imprimir(f, pos);
            break;
        case 4:
            printf("Digite a posicao q quer excluir: ");
            scanf("%d", &aux);
            excluir(f, &pos, aux);
            break;
        default:
            break;
        }
    } while (opc != -1);

    return 0;
}