#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int chave;
    char nome[50];
    int idade;
    char motivo_consulta[100];
} REGISTRO_PACIENTE;

typedef struct item
{
    REGISTRO_PACIENTE r;
    struct item *prox;
} ITEM;

typedef struct
{
    ITEM *inicio;
    ITEM *fim;
    int qtde;
} FILA;

void inicializar(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
}
ITEM *criarItem(REGISTRO_PACIENTE r)
{
    ITEM *novo = (ITEM *)malloc(sizeof(ITEM));
    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
    }
    return novo;
}

void inserir(FILA *f, REGISTRO_PACIENTE r)
{
    ITEM *novo = criarItem(r);
    if (novo)
    {
        if (!f->inicio)
        {
            f->inicio = novo;
        }
        else if (f->fim)
        {
            f->fim->prox = novo;
        }
        f->fim = novo;
        f->qtde++;
    }
}

void remover(FILA *f)
{
    if (f->inicio)
    {
        ITEM *excluir = f->inicio;
        f->inicio = f->inicio->prox;
        free(excluir);
        f->qtde--;
    }
}

void imprimir(FILA *f)
{
    ITEM *pos = f->inicio;
    while (pos)
    {
        printf("Chave: %d, Nome: %s, Idade: %d, Motivo da consulta: %s\n", pos->r.chave, pos->r.nome, pos->r.idade, pos->r.motivo_consulta);
        pos = pos->prox;
    }
}

int main(void)
{
    FILA f;
    inicializar(&f);
    printf("Iniciei a fila\n");
    int opc, chave = 1;
    char nome_aux[50], motivo[100];
    int idade = 0;
    do
    {
        printf("-1 - Sair\n");
        printf(" 1 - Inserir novo paciente\n");
        printf(" 2 - Chamar o proximo paciente\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case -1:
            printf("Tchau :D");
            break;
        case 1:
            printf("Nome: ");
            fflush(stdin);
            fgets(nome_aux, sizeof(nome_aux), stdin);
            nome_aux[strcspn(nome_aux, "\n")] = '\0'; // Remover a quebra de linha do final
            printf("Motivo: ");
            fflush(stdin);
            fgets(motivo, sizeof(motivo), stdin);
            motivo[strcspn(motivo, "\n")] = '\0'; // Remover a quebra de linha do final
            printf("Idade: ");
            scanf("%d", &idade);

            REGISTRO_PACIENTE paciente1;
            paciente1.chave = chave;
            strcpy(paciente1.nome, nome_aux);
            paciente1.idade = idade;
            strcpy(paciente1.motivo_consulta, motivo);
            inserir(&f, paciente1);
            chave++;
            break;
        case 2:
            printf("proximo paciente: ");
            printf("Chave: %d, Nome: %s, Idade: %d, Motivo: %s\n", f.inicio->r.chave, f.inicio->r.nome, f.inicio->r.idade, f.inicio->r.motivo_consulta);
            printf("Voce terminou de atender esse paciente? Podemos manda-lo embora? Sim-0 / Nao ");
            int aux;
            scanf("%d", &aux);
            if (aux == 0)
            {
                remover(&f);
            }
            else
            {
                printf("não vamos remove-lo ");
            }
            break;
        default:
            break;
        }
        if (opc == -1)
        {
            break;
        }
        else
        {
            printf("Sua fila de espera está assim: \n ");
            imprimir(&f);
        }

    } while (opc != -1);
    /*inserir(&f, (REGISTRO_PACIENTE){20});
    inserir(&f, (REGISTRO_PACIENTE){30});
    inserir(&f, (REGISTRO_PACIENTE){40});
    imprimir(&f);
    remover(&f);
    remover(&f);
    inserir(&f, (REGISTRO_PACIENTE){50});
    imprimir(&f);*/
}