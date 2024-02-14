#include <stdio.h>

typedef struct 
{
    int idade;
    float altura;
    float salario;
} Pessoa;

int main(void)
{
    FILE *arquivoPessoa = fopen("arquivoPessoa.txt", "r");
    if (!arquivoPessoa)
    {
        printf("Erro ao abrir arquivoPessoa para leitura.\n");
        return 1;
    }

    Pessoa cebolinha = (20, 1.45, 2000);

    // Lendo dados formatados do arquivo com fscanf
    while (fscanf(arquivoPessoa, "%49s %d", cebolinha.idade, &idade) != EOF) {
        printf("Nome: %s, Idade: %d\n", nome, idade);
    }

    fclose(arquivoPessoa);

    int *pontSimples = &luz;
    // 0 apagada
    // 1 acesa

    void (*ponteiro_ligar)(int *);
    ponteiro_ligar = ligar;

    void (*ponteiro_desligar)(int *);
    ponteiro_desligar = desligar;

    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);
    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);
    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);

    arquivoPessoa = fopen("arquivoPessoa.txt", "w");
    if (!arquivoPessoa)
    {
        printf("Erro ao abrir arquivoPessoa para escrita.\n");
        return 1;
    }

    fprintf(arquivoPessoa, " %d\n", luz);

    fclose(arquivoPessoa);
    return 0;
}
