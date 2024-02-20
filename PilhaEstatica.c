#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct
{
    int chave;
    /*
    int chave;
    char nome[30];
    float salario;
    */
} Registro;

typedef struct
{
    Registro registros[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p)
{
    p->topo = 0;
}

void empilhar(Pilha *p, Registro r)
{
    if (p->topo < TAM) // se a pilha estiver no maximo
    {
        p->registros[p->topo] = r;
        p->topo++;
    }
    else
    {
        printf("Pilha cheia!\n");
    }
}

void desempilhar(Pilha *p)
{
    if (p->topo > 0)
    {
        p->topo--;
    }
}

void imprimir(Pilha *p)
{
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("chave: %d\n", p->registros[i].chave);
    }
}

int main()
{
    Pilha p;
    printf("Criei a pilha p\n");
    
    //Registro r = {1}; // Registro r = {1, "Jose", 7500};         ou      empilhar(&p, (Registro){10});
    //printf("Criei o registro r=1\n");
    
    inicializar(&p);
    printf("Inicializar p\n");
    
    empilhar(&p, (Registro){10});
    empilhar(&p, (Registro){20});
    empilhar(&p, (Registro){30});
    printf("Empilhar e imprimir\n");
    imprimir(&p);
    desempilhar(&p);
    imprimir(&p);

    return 0;
}
