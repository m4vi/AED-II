/*Elabore um programa em C para gerenciar o registro
de veículos de uma concessionária. Use uma struct
chamada Veiculo contendo variáveis para modelo, marca, ano de fabricação, cor e preço. Guarde vários registros de veículos em um vetor dessa struct. Implemente funções para salvar os registros em um arquivo e carregá-los quando o programa for iniciado. Desenvolva uma interface de usuário simples para adicionar
novos veículos, exibir todos os registros e
atualizar os dados salvos.*/

#include <stdio.h>

typedef struct
{
    char modelo[30];
    char marca[30];
    int ano_de_fabricacao;
    char cor[30];
    float preco;
} Veiculos;

void CadastrarDados(Veiculos VetorVeiculo)
{
    printf("1 - funcionario nome\n");
    printf("2 - funcionario codigo \n");
    printf("3 - departamento nome\n");
    printf("4 - departamento codigo\n");
    printf("5 - departamento de um funcionario\n");
    printf("O que deseja atualizar: ");
    scanf("%d", &);
}
int main(void)
{
    Veiculos *vVeiculos;
    Veiculos *vVeiculos = (Veiculos *)calloc(4, sizeof(Veiculos));

    void CadastrarDados(vVeiculos);

    FILE *arquivo = fopen("arquivo.txt", "w");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 1;
    }

    int luz = 0;

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &luz);
    }
    else
        printf("Erro\n");

    fclose(arquivo);

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

    arquivo = fopen("arquivo.txt", "w");
    if (!arquivo)
    {
        printf("Erro ao abrir arquivo para escrita.\n");
        return 1;
    }

    fprintf(arquivo, " %d\n", luz);

    fclose(arquivo);
    return 0;
}