/*Uma estudante de "Algoritmos e Estruturas de Dados II", fascinada com o conteúdo da disciplina 🙃, está criando um módulo de playlists para um aplicativo de música como o Spotify. Uma playlist, evidentemente, pode conter diversas músicas. Como no Spotify, músicas mais recentes são as primeiras a serem exibidas na lista. Para facilitar a vida dos usuários, ela deseja implementar o seguinte recurso em seu programa: uma opção de desfazer e refazer a inserção de músicas na playlist, que funciona da seguinte forma:

a) se o usuário selecionar a opção desfazer, a última música inserida na playlist será removida;
b) se o usuário selecionar a opção refazer, a último música excluída voltará para a playlist;

Implemente um programa que funciona como o descrito acima.

Considere a implementação DINÂMICA da estrutura.
Atenção: a entrega deve ser feita em arquivos .c diretamente, sem compactação. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    char cantor[30];
} REGISTRO;

typedef struct item
{
    REGISTRO r;
    struct item *ant;
} ITEM;

typedef struct
{
    ITEM *topo;
    int tam;
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
    p->tam = 0;
}

ITEM *criarItem(REGISTRO r)
{
    ITEM *novo = (ITEM *)malloc(sizeof(ITEM));
    if (novo)
    {
        novo->r = r;
        novo->ant = NULL;
        return novo;
    }
    return NULL;
}

void empilhar(PILHA *p, REGISTRO r)
{
    ITEM *novo = criarItem(r);
    novo->ant = p->topo;
    p->topo = novo;
}

void desempilhar(PILHA *p)
{
    if (p->topo)
    {
        ITEM *deletar = p->topo;
        p->topo = p->topo->ant;
        p->tam--;
        free(deletar);
    }
}

void imprimir(PILHA *p)
{
    ITEM *pos = p->topo;
    while (pos)
    {
        printf("Nome: %s, Cantor: %s\n", pos->r.nome, pos->r.cantor);
        pos = pos->ant;
    }
}

int main(void)
{
    PILHA p;
    inicializarPilha(&p);
    printf("Criei a pilha e iniciei ela\n");
    empilhar(&p, (REGISTRO){"Descobridor dos 7 mares", "Tim Maia"});
    empilhar(&p, (REGISTRO){"No digas nada", "RBD"});
    printf("Suas musicas sao essas: \n");
    imprimir(&p);

    int numero;
    printf("Quer adicionar outra musica? 1 Sim - 2 Nao ");
    scanf("%d", &numero);
    if (numero == 1)
    {
        empilhar(&p, (REGISTRO){"Roi", "Videoclub"});
        printf("Suas musicas sao essas: \n");
        imprimir(&p);
    }
    else
    {
        printf("Suas musicas sao essas: \n");
        imprimir(&p);
    }
    printf("\nVamos desfazer!");
    REGISTRO auxiliar;
    auxiliar = p.topo->r;
    desempilhar(&p);
    printf("Suas musicas sao essas: \n");
    imprimir(&p);

    printf("\nDeseja Desfazer ou refazer? \n 1-Desfazer \n 2-Refazer \n");
    scanf("%d", &numero);

    if (numero == 1)
    {
        auxiliar = p.topo->r;
        desempilhar(&p);
    }
    else if (numero == 2)
    {
        empilhar(&p, auxiliar);
    }
    else
    {
        printf("opc incorreta\n");
    }
    printf("Suas musicas sao essas: \n");
    imprimir(&p);

    printf("\nQuer adicionar outra musica? 1 Sim - 2 Nao ");
    scanf("%d", &numero);
    if (numero == 1)
    {
        empilhar(&p, (REGISTRO){"Just a man", "Jorge Rivvera-Herrans"});
        printf("Suas musicas são essas: \n");
        imprimir(&p);
    }
    else
    {
        printf("Suas musicas sao essas: \n");
        imprimir(&p);
    }

    printf("\nDeseja Desfazer ou refazer? \n 1-Desfazer \n 2-Refazer \n");
    scanf("%d", &numero);

    if (numero == 1)
    {
        auxiliar = p.topo->r;
        desempilhar(&p);
    }
    else if (numero == 2)
    {
        empilhar(&p, auxiliar);
    }
    else
    {
        printf("opc incorreta\n");
    }
    printf("Suas musicas sao essas: \n");
    imprimir(&p);
}
