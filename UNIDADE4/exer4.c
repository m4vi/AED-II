/*O Orkut, primeira rede social
a se popularizar no Brasil,
permitia inicialmente que seus
usuários enviassem apenas doze fotos.
Além do caminho de cada imagem ("fotonapraia.jpg"),
o usuário poderia também adicionar uma legenda e
autoavaliar a sua imagem de 0 a 5 estrelas. Além da
visualização do álbum com todas as fotos já
enviadas, o usuário poderia excluir as imagens
já cadastradas e, se ainda houvesse espaço,
adicionar novas imagens ao seu álbum.
Apresente como esse recurso tão importante
na época poderia ser implementado em C,
usando a estrutura de dados mais adequada
para tal situação. */
#include <stdio.h>
#include <stdlib.h>

#define TAM 12
#define INEXISTENTE -1

typedef struct
{
    int chave;
    char caminho_da_imagem[30];
    char legenda[50];
    int estrelas; //de 0 a 5 estrelas
    
} FOTOSS;

typedef struct
{
    FOTOSS r;
    int prox;
} ITEM;

typedef struct
{
    ITEM itens[TAM];
    int inicio;
    int dispo;
} ORKUT;

void inicializar(ORKUT *l)
{

    l->inicio = INEXISTENTE;
    l->dispo = 0;

    for (int i = 0; i < TAM - 1; i++)
    {
        l->itens[i].prox = i + 1;
    }
    l->itens[TAM - 1].prox = INEXISTENTE;
}

void inserir(ORKUT *l, FOTOSS r)
{
    if (l->dispo != INEXISTENTE)
    {
        int novo = l->dispo;
        l->dispo = l->itens[l->dispo].prox;

        if (l->inicio == INEXISTENTE)
        {
            l->inicio = novo;
        }
        else
        {
            int pos = l->inicio;
            int ant = INEXISTENTE;
            while (pos != INEXISTENTE)
            {
                ant = pos;
                pos = l->itens[pos].prox;
            }
            l->itens[ant].prox = novo;
        }
        l->itens[novo].r = r;
        l->itens[novo].prox = INEXISTENTE;
    }
    else
    {
        printf("Lista cheia!\n");
    }
}

void remover(ORKUT *l, FOTOSS r)
{
    int ant = INEXISTENTE;
    int pos = l->inicio;

    while (pos != INEXISTENTE && l->itens[pos].r.chave != r.chave)
    {
        ant = pos;
        pos = l->itens[pos].prox;
    }
    if (pos == INEXISTENTE)
        return;

    if (ant == INEXISTENTE)
    {
        l->inicio = l->itens[pos].prox;
    }
    else
    {
        l->itens[ant].prox = l->itens[pos].prox;
    }

    // Adicionar à ORKUT de disponíveis
    l->itens[pos].prox = l->dispo;
    l->dispo = pos;
}

void imprimir(ORKUT *l)
{
    int pos = l->inicio;
    while (pos != INEXISTENTE)
    {
        printf("Chave %d, Caminho de imagem: %s, legenda: %s, %d estrelas!\n", l->itens[pos].r.chave, l->itens[pos].r.caminho_da_imagem, l->itens->r.legenda, l->itens->r.estrelas);
        pos = l->itens[pos].prox;
    }
}

int main(void){
    ORKUT l;
    inicializar(&l);
    printf("Vamos inserir fotos!\n");
    inserir(&l, (FOTOSS){1, "foto_no_jardim.jpg", "LEGENDA FOFA :D", 5});
    inserir(&l, (FOTOSS){2, "foto_no_castelo.jpg", "LEGENDA ASSUSTADORA :o", 3});
    inserir(&l, (FOTOSS){3, "foto_no_trabalho.jpg", "LEGENDA CHATA :/", 1});
    
    imprimir(&l);
    printf("Vamos excluir uma foto: \n");
    remover(&l, (FOTOSS){3, "foto_no_trabalho.jpg", "LEGENDA CHATA :/", 1});

    imprimir(&l);

    printf("Vamos inserir fotos!\n");
    inserir(&l, (FOTOSS){3, "foto_no_casamento.jpg", "LEGENDA ROMANTICA <3", 5});
    inserir(&l, (FOTOSS){4, "foto_na_faculdade.jpg", "LEGENDA COACH --", 4});
    imprimir(&l);
    return 0;
}