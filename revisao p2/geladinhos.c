/*A Geladinhos Cuiabá é uma sorveteria que está a inaugurar na cidade que atenderá tanto presencialmente quanto via delivery. Para controlar as solicitações, o gerente da empresa contratou você para desenvolver um sistema. Ocorre que, pela política da empresa, os pedidos mais caros devem ser atendidos com prioridade. Considerando as estruturas lista, pilha e fila, nas versões abordadas na disciplina, escolha aquela que pode atender ao requisito do cliente. Em seguida, apresente a declaração das estruturas necessárias. Explique também como a questão do tratamento diferenciado pode ser resolvida na implementação. */

#include <stdio.h>
#define TAM 3
typedef struct{
    float preco;
} SORVETE;

typedef struct{
    SORVETE SORVETEs[TAM];
    int qtde;
} LISTA;

void inicializar(LISTA *l){
    l->qtde = 0;
}
//Inserindo um item na fila

void inserir(LISTA *l, SORVETE r){
    if(l->qtde < TAM){
        l->SORVETEs[l->qtde] = r;
        l->qtde++;
    }
}

int buscar(LISTA *l, SORVETE r){
    for(int i = 0; i < l->qtde; i++){
        if(l->SORVETEs[i].preco
 == r.preco
){
            return i;
        }
    }
    return -1;
}

void remover(LISTA *l, SORVETE r){
    int pos = buscar(l, r);
    if(pos>=0){
        for(int i = pos; i < l->qtde - 1; i++){
            l->SORVETEs[i] = l->SORVETEs[i+1];
        }
        l->qtde--;
    }
}

void imprimir(LISTA *l){
    for(int i = 0; i < l->qtde; i++){
        printf("%d\n", l->SORVETEs[i].preco
);
    }
}


void bubbleSortDecrescente(SORVETES v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].preco < v[j + 1].preco)
            {
                // trocar 
                int aux = v[j].preco;
                v[j].preco = v[j + 1].preco;
                v[j + 1].preco = aux;
                
            }
        }
    }
}

int main()
{
    LISTA l;
    bubbleSortDecrescente(geladinho, 10);
    return 0;
}