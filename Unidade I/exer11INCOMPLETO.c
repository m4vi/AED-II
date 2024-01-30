/*Uma estudante de Algoritmos e Estrutura de Dados II deseja implementar com conjunto de funções/procedimentos para facilitar a criação de vetores alocados dinamicamente na memória, oferecendo recursos que possibilitem:

a) a criação de um novo vetor;

b) a inserção de valores no vetor, lidos do teclado;

c) a impressão do vetor;

d) a mudança da capacidade de armazenamento do vetor, para mais ou para menos;

e) a liberação do espaço de memória ocupado pelo vetor;*/
#include <stdio.h>
#include <stdlib.h>

int criar_vetor()
{
    int aux;
    printf("qual o tamanho? ");
    scanf("%d", &aux);
    int *vetorAlocDinamica = (int *)calloc(aux, sizeof(int));
    return *vetorAlocDinamica;
}
void insercao_de_valores(int *vetorAlocDinamica)
{
    for (int i = 0; (vetorAlocDinamica[i]) = !0; i++)
    {
        printf("insira o valor da posicao [%d]: \n", i);
        scanf("%d", vetorAlocDinamica[i]);
    }
}
void realocar(int *vetor)
{
    int aux;
    printf("Para quanto vc quer realocar? ");
    scanf("%d", &aux);
    int *realocado = (int *)realloc(vetor, sizeof(int) * aux);
    //printf("A: %p\n", vetor);
    //printf("Realocado: %p\n", realocado);

    if (realocado != NULL)
    {
        vetor = realocado;
    }
}

/*
void impressão_do_vetor(int *vetorAlocDinamica)
{
    for (int i = 0; *(vetorAlocDinamica) = !0; i++)
    {
        printf("%d\n", vetorAlocDinamica[i]);
    }
}*/
int main()
{
    int *ponteiro;
    printf("Agora vc vai criar o vetor\n");
    *ponteiro = criar_vetor();

    printf("Agora vc vai inserir os valores\n");
    insercao_de_valores(*ponteiro);

    printf("Agora vc vai imprimir os valores\n");
    //impressão_do_vetor(*ponteiro);

    printf("Agora vc vai realocar o tam\n");
    realocar(*ponteiro);

    return 0;
}