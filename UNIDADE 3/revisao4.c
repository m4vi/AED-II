#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[30];
    int codigo;
} Curso;

typedef struct
{
    char nome[30];
    int idade;
    Curso *cursinho;
} Estudante;

void cadastrar_Departamento(Curso cursinho[], int *pos)
{
    scanf("%s[\n]30", cursinho[*pos].nome);
    scanf("%d", &cursinho[*pos].codigo);
}
void cadastrar(Estudante *p, Curso c[], int *pos_curso)
{
    scanf("%s[\n]30", p->nome);
    scanf("%d", &p->idade);

    printf("curso cadastrado: 1 S/ 2 N: ");
    int opc;
    scanf("%d", &opc);

    int posicao;
    if (opc == 1) // cadastrado ja
    {
        printf("digite a posicao do vetor: ");
        scanf("%d", &posicao);

        p->cursinho = &c[posicao];
    }
    else if (opc == 2) // tem q cadastrar
    {
        cadastrar_Departamento(c, pos_curso);
        p->cursinho = &c[*pos_curso];
        (*pos_curso)++;
    }
}

void listar(Estudante e[], int pos)
{
    for (int i = 0; i < pos; i++)
    {
        printf("nome: %s, idade: %d, curso: %s, codigo: %d \n", e[i].nome, e[i].idade, e[i].cursinho->nome, e[i].cursinho->codigo);
    }
}

void atualizar(Estudante e[], int pos, Curso c[], int *posCurso)
{
    scanf("%s[\n]30", p->nome);
    scanf("%d", &p->idade);

    printf("curso cadastrado: 1 S/ 2 N: ");
    int opc;
    scanf("%d", &opc);

    int posicao;
    if (opc == 1) // cadastrado ja
    {
        printf("digite a posicao do vetor: ");
        scanf("%d", &posicao);

        p->cursinho = &c[posicao];
    }
    else if (opc == 2) // tem q cadastrar
    {
        cadastrar_Departamento(c, pos_curso);
        p->cursinho = &c[*pos_curso];
        (*pos_curso)++;
    }
    int main()
    {
        Curso c[5];
        Estudante e[5];
        int pos_e = 0, pos_c = 0;
        printf("cadastrar 1: ");
        cadastrar(&e[pos_e], c, &pos_c);
        pos_e++;
        printf("cadastrar 2: ");
        pos_e++;
        cadastrar(&e[pos_e], c, &pos_c);

        printf("listar: ");
        listar(e, pos_e);

        printf("atualizar: ");
        atualizar(e, 0, c, &pos_c);
        printf("listar: ");
        listar(e, pos_e);

        return 0;
    }