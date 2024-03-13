#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int chave;
    char publicacao[144];
    char identificacao_de_usuario[50];
} REGISTRO;

typedef struct item
{
    REGISTRO r;
    struct item *prox;
} ITEM;

typedef struct
{
    ITEM *inicio;
    int qtde;
} LISTA;

void inicializar(LISTA *l)
{
    l->inicio = NULL;
    l->qtde = 0;
}

ITEM *criarItem(REGISTRO r)
{
    ITEM *novo = (ITEM *)malloc(sizeof(ITEM));
    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void inserir(LISTA *l, REGISTRO r)
{
    ITEM *novo = criarItem(r);

    ITEM *pos = l->inicio;
    ITEM *ant = NULL;
    while (pos)
    {
        ant = pos;
        pos = pos->prox;
    }
    if (!ant)
    {
        l->inicio = novo;
    }
    else
    {
        ant->prox = novo;
    }
    l->qtde++;
}

void remover(LISTA *l, REGISTRO r)
{
    if (!l->inicio)
        return;

    ITEM *pos = l->inicio;
    ITEM *ant = NULL;
    while (pos && pos->r.chave != r.chave)
    {
        ant = pos;
        pos = pos->prox;
    }

    if (!pos)
        return;

    if (!ant)
    {
        l->inicio = l->inicio->prox;
    }
    else
    {
        ant->prox = pos->prox;
    }
    free(pos);
    l->qtde--;
}

void imprimir(LISTA *l)
{
    ITEM *pos = l->inicio;
    while (pos)
    {
        printf("Codigo: %d, Autor: %s, Publicacao: %s\n", pos->r.chave ,pos->r.identificacao_de_usuario,pos->r.publicacao);
        pos = pos->prox;
    }
}

int main(void)
{
    LISTA l;
    inicializar(&l);
    int opc, chave = 0;
    char nome_aux[50], publicacao[144];
    do
    {
        printf("-1 - Sair\n");
        printf(" 1 - Inserir nova publicacao\n");
        printf(" 2 - Visualizar as suas publicacoes\n");
        printf(" 3 - Excluir uma publicacao\n");
        scanf("%d", &opc);
        REGISTRO auxiliar;
        switch (opc)
        {
        case -1:
            printf("Tchau :D");
            break;
        case 1: // inserir uma nova publicação, digitando o seu conteúdo
            printf("Nome do usuario: ");
            fflush(stdin);
            fgets(nome_aux, sizeof(nome_aux), stdin);
            nome_aux[strcspn(nome_aux, "\n")] = '\0'; // Remover a quebra de linha do final
            printf("Publicacao: ");
            fflush(stdin);
            fgets(publicacao, sizeof(publicacao), stdin);
            publicacao[strcspn(publicacao, "\n")] = '\0'; // Remover a quebra de linha do final

            
            auxiliar.chave = chave;
            strcpy(auxiliar.identificacao_de_usuario, nome_aux);
            strcpy(auxiliar.publicacao, publicacao);
            inserir(&l, auxiliar);
            chave++;
            break;
        case 2: //visualizar as publicaçõe
            imprimir(&l);
            break;
        case 3:
            printf("Digite a chave da publicacao que vc quer excluir");
            int excluir;
            scanf("%d", &excluir);

            auxiliar.chave = excluir;
    
            remover(&l, auxiliar);
            break;
        default:
            break;
        }
    } while (opc != -1);


    return 0;
}
