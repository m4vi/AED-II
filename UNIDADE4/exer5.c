#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int chave;
} REGISTRO;

typedef struct item{
    REGISTRO r;
    struct item *prox;
} ITEM;

typedef struct
{
    ITEM *inicio;
    int qtde;
} LISTA;

void inicializar(LISTA *l){
    l->inicio = NULL;
    l->qtde = 0;
}

ITEM* criarItem(REGISTRO r){
    ITEM* novo = (ITEM*) malloc(sizeof(ITEM));
    if(novo){
        novo->r = r;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void inserir(LISTA *l, REGISTRO r){
    ITEM *novo = criarItem(r);
    
    ITEM *pos = l->inicio;
    ITEM *ant = NULL;
    while (pos){
        ant = pos;
        pos = pos->prox;
    }
    if (!ant){
        l->inicio = novo;
    }
    else{
        ant->prox = novo;
    }
    l->qtde++;
}

void remover(LISTA *l, REGISTRO r){
    if(!l->inicio) return;

    ITEM *pos = l->inicio;
    ITEM *ant = NULL;
    while(pos && pos->r.chave!=r.chave){
        ant = pos;
        pos = pos->prox;
    }

    if(!pos) return;

    if(!ant){
        l->inicio = l->inicio->prox;        
    }
    else{
        ant->prox = pos->prox;

    }
    free(pos);
    l->qtde--;

}

void imprimir(LISTA *l){
    ITEM *pos = l->inicio;
    while (pos){
        printf("%d\n", pos->r.chave);
        pos = pos->prox;
    }
}

int main(void){
    LISTA l;
    inicializar(&l);
    inserir(&l, (REGISTRO){10});
    inserir(&l, (REGISTRO){20});
    inserir(&l, (REGISTRO){30});
    
    remover(&l, (REGISTRO){20});
    inserir(&l, (REGISTRO){40});
    
    imprimir(&l);
    return 0;
}

