/*Uma estudante de Algoritmos e Estrutura de Dados II deseja implementar com conjunto de funções/procedimentos para facilitar a criação de vetores alocados dinamicamente na memória, oferecendo recursos que possibilitem:

a) a criação de um novo vetor;

b) a inserção de valores no vetor, lidos do teclado;

c) a impressão do vetor;

d) a mudança da capacidade de armazenamento do vetor, para mais ou para menos;

e) a liberação do espaço de memória ocupado pelo vetor;*/
#include <stdio.h>
#include <stdlib.h>

int *criar_vetor(int *aux)
{

    int *vetorAlocDinamica = (int *)calloc(*aux, sizeof(int));
    return vetorAlocDinamica;
}
void insercao_de_valores(int *vetorAlocDinamica, int *aux)
{
    for (int i = 0; i < *aux; i++)
    {
        printf("insira o valor da posicao [%d]: \n", i);
        scanf("%d", vetorAlocDinamica + i);
    }
}
void realocar(int *vetor, int *num)
{
    int aux;
    printf("Para quanto vc quer realocar? ");
    scanf("%d", &aux);
    int *realocado = (int *)realloc(vetor, sizeof(int) * aux);
    // printf("A: %p\n", vetor);
    // printf("Realocado: %p\n", realocado);

    if (realocado != NULL)
    {
        vetor = realocado;
        *num = aux;
    }
    else
    {
        printf("Nao ha memoria disponivel. ");
    }
}

void impressao_do_vetor(int *vetorAlocDinamica, int *aux)
{
    for (int i = 0; i < *aux; i++)
    {
        printf("%d\n", vetorAlocDinamica[i]);
    }
}

int main()
{
    int *ponteiro;
    printf("Agora vc vai criar o vetor\n");
    int aux;
    printf("qual o tamanho? ");
    scanf("%d", &aux);
    ponteiro = criar_vetor(&aux);

    int opc;
    do
    {
        printf("\n-1 - sair\n");
        printf(" 1 - inserir valores\n");
        printf(" 2 - imprimir valores\n");
        printf(" 3 - realocar tamanho\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opc);

    switch (opc)
    {
    case -1:
        /* code */
        break;
    case 1:
        printf("Agora vc vai inserir os valores\n");
        insercao_de_valores(ponteiro, &aux);
        break;
    case 2: 
        printf("Agora vc vai imprimir os valores\n");
        impressao_do_vetor(ponteiro, &aux);
        break;
    case 3:
        printf("Agora vc vai realocar o tam\n");
        realocar(ponteiro, &aux);
        free(ponteiro);
        break;
    default:
        break;
    }
    } while (opc != -1);

    return 0;
}