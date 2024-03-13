#include <stdio.h>
#include<stdlib.h>

typedef struct{
    int chave;
} REGISTRO;

typedef struct item{
    REGISTRO r;
    struct item* prox;
} ITEM;

typedef struct{
    ITEM *inicio;
    ITEM *fim;
    int qtde;
} FILA;

void inicializar(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
}

ITEM* criarItem(REGISTRO r){
    ITEM *novo = (ITEM*)malloc(sizeof(ITEM));
    if(novo){
        novo->r = r;
        novo->prox = NULL;
    }
    return novo;
}
void inserir(FILA *f, REGISTRO r){
    ITEM *novo = criarItem(r);
    if(novo){
        if(!f->inicio){
            f->inicio = novo;
        }
        else if(f->fim){
            f->fim->prox = novo;
        }
        f->fim = novo;
        f->qtde++;
    }
}

void remover(FILA *f){
    if(f->inicio){
        ITEM *excluir = f->inicio;
        f->inicio = f->inicio->prox;
        free(excluir);
        f->qtde--;
    }
}

void imprimir(FILA *f){
    ITEM* pos = f->inicio;
    while(pos){
        printf("%d\n", pos->r.chave);
        pos = pos->prox;
    }
}

int main(void){
    FILA f;
    inicializar(&f);
    inserir(&f, (REGISTRO){10});
    inserir(&f, (REGISTRO){20});
    inserir(&f, (REGISTRO){30});
    inserir(&f, (REGISTRO){40});
    imprimir(&f);
    remover(&f);
    remover(&f);
    inserir(&f, (REGISTRO){50});
    imprimir(&f);
}
