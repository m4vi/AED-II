/*Em um prédio de Cuiabá, há uma garagem
estreita, porém comprida. Sua largura
contém espaço suficiente para um único
veículo, além da passagem para o motorista.
Assim, os carros são estacionados um atrás
do outro, sem exceção. Para remover um carro,
é preciso que todos os demais sejam removidos
também. Como o prédio não tem manobrista, em
todas as manhãs o cenário é de correria e
confusão. Para tentar agilizar o processo,
o porteiro Ribamar implementou um sistema
de informação que registra, para cada carro, a placa e
o número do apartamento do proprietário. Quando um
morador chega para retirar seu carro, ele informa a
placa do seu veículo e o programa retorna: a
quantidade de veículos a serem retirados primeiro,
bem como o números dos apartamentos dos proprietários
dos veículos envolvidos.
Implemente esse programa em C, usando uma estrutura
de dados adequada para essa finalidade.

Atenção: a entrega deve ser feita em arquivos .c diretamente,
sem compactação. Considere a implementação ESTÁTICA da estrutura.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int num_apartamento;
    char placa[10];
    /*
    int chave;
    char nome[30];
    float salario;
    */
} REGISTRO_CARRO;

typedef struct
{
    REGISTRO_CARRO registrs_carros[TAM];
    int topo;
} PILHA_GARAGEM;

void inicializar(PILHA_GARAGEM *p)
{
    p->topo = 0;
}

void empilhar(PILHA_GARAGEM *p, REGISTRO_CARRO r)
{
    if (p->topo < TAM) // se a pilha estiver no maximo
    {
        p->registrs_carros[p->topo] = r;
        p->topo++;
    }
    else
    {
        printf("pilha cheia!\n");
    }
}

void desempilhar(PILHA_GARAGEM *p)
{
    if (p->topo > 0)
    {
        p->topo--;
    }
}

void imprimir(PILHA_GARAGEM *p)
{
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("Numero de apartamento: %d, Placa: %s\n", p->registrs_carros[i].num_apartamento, p->registrs_carros[i].placa);
    }
}

int main()
{
    PILHA_GARAGEM p;
    printf("Criei a pilha p\n");
    inicializar(&p);
    printf("Inicializar p\n");

    empilhar(&p, (REGISTRO_CARRO){2, "NMB2566"});
    empilhar(&p, (REGISTRO_CARRO){3, "ABDC5783"});
    empilhar(&p, (REGISTRO_CARRO){6, "SDFG9075"});
    printf("Empilhei e imprimi\n");

    imprimir(&p);

    char placa_aux[10];
    printf("Qual placa do carro vc quer tirar: ");
    scanf("%s", placa_aux);

    printf("Para isso voce tem que tirar o(s) carro(s)\n");
    int ret;
    for (int i = p.topo - 1; i >= 0; i--)
    {
        ret = strcmp(placa_aux, p.registrs_carros[i].placa);
        if (ret == 0)
        {
            break;
        }
        else
        {
            printf("Número do ap: %d, Placa: %s", p.registrs_carros[i].num_apartamento, p.registrs_carros[i].placa);
        }
    }

    printf("Fim!");

    return 0;
}

// fgets(p.nome, 50, stdin);
// scanf("%s", &p.sexo);