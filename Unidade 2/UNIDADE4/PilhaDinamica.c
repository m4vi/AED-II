#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
}REGISTRO;

typedef struct item
{
    REGISTRO r;
    struct item *prox;
}ITEM;

typedef struct
{
    ITEM *topo;
    int tam;
}PILHA;

void inicializar(PILHA *p)
{
    p->topo = NULL;
    p->tam = 0;
}

ITEM *CriarItem(REGISTRO r)
{
    ITEM *novo = (ITEM *)malloc(sizeof(ITEM));
    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
    }
    return novo;
}

void empilhar(PILHA *p, REGISTRO r)
{
    ITEM *novo = CriarItem(r);
    novo->prox - p->topo;
    p->topo = novo;
    p->tam++;
}

void desempilhar(PILHA *p)
{
    if (p->topo)
    {
        ITEM *deletar = p->topo;
        p->topo = p->topo->prox;
        free(deletar);
        p->tam--;
    }
}

void imprimir(PILHA *p)
{
    ITEM *pos = p->topo; // pos = proximo
    while (pos) // enquanto proximo for diferente de null
    {
        printf("chave: %d \n", pos->r.chave);
        pos = pos->prox;
    }    
}

int main ()
{
    PILHA p;
    inicializar(&p);
    printf("Inicializar p\n");
    empilhar(&p, (REGISTRO){10});
    empilhar(&p, (REGISTRO){20});
    empilhar(&p, (REGISTRO){30});
    
    printf("Empilhar e Imprimir\n");
    imprimir(&p);
    desempilhar(&p);
    imprimir(&p);
    return 0;
}
