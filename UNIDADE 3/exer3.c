#include <stdio.h>
#include <stdlib.h>

#define MAX_VEICULOS 100

// Definindo a struct Veiculo
struct Veiculo {
    char modelo[50];
    char marca[50];
    int anoFabricacao;
    char cor[20];
    float preco;
};

// Função para salvar registros em um arquivo
void salvarRegistros(struct Veiculo veiculos[], int totalVeiculos) {
    FILE *arquivo = fopen("registros_veiculos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    for (int i = 0; i < totalVeiculos; i++) {
        fprintf(arquivo, "%s %s %d %s %.2f\n",
                veiculos[i].modelo, veiculos[i].marca,
                veiculos[i].anoFabricacao, veiculos[i].cor,
                veiculos[i].preco);
    }

    fclose(arquivo);
}

// Função para carregar registros de um arquivo
int carregarRegistros(struct Veiculo veiculos[]) {
    FILE *arquivo = fopen("registros_veiculos.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de registros nao encontrado. Criando novo arquivo.\n");
        return 0; // Sem registros carregados
    }

    int totalVeiculos = 0;
    while (fscanf(arquivo, "%s %s %d %s %f\n",
                  veiculos[totalVeiculos].modelo, veiculos[totalVeiculos].marca,
                  &veiculos[totalVeiculos].anoFabricacao, veiculos[totalVeiculos].cor,
                  &veiculos[totalVeiculos].preco) == 5) {
        totalVeiculos++;
    }

    fclose(arquivo);
    return totalVeiculos;
}

// Função para exibir todos os registros
void exibirRegistros(struct Veiculo veiculos[], int totalVeiculos) {
    printf("Registros de Veiculos:\n");
    for (int i = 0; i < totalVeiculos; i++) {
        printf("Modelo: %s, Marca: %s, Ano: %d, Cor: %s, Preço: %.2f\n",
                veiculos[i].modelo, veiculos[i].marca,
                veiculos[i].anoFabricacao, veiculos[i].cor,
                veiculos[i].preco);
    }
}

int main() {
    struct Veiculo veiculos[MAX_VEICULOS];
    int totalVeiculos = 0;

    // Carregar registros existentes
    totalVeiculos = carregarRegistros(veiculos);

    int opcao;
    do {
        printf("\n1. Adicionar novo veiculo\n");
        printf("2. Exibir todos os registros\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalVeiculos < MAX_VEICULOS) {
                    printf("\nDigite os detalhes do veiculo:\n");
                    printf("Modelo: ");
                    scanf("%s", veiculos[totalVeiculos].modelo);
                    printf("Marca: ");
                    scanf("%s", veiculos[totalVeiculos].marca);
                    printf("Ano de Fabricacao: ");
                    scanf("%d", &veiculos[totalVeiculos].anoFabricacao);
                    printf("Cor: ");
                    scanf("%s", veiculos[totalVeiculos].cor);
                    printf("Preco: ");
                    scanf("%f", &veiculos[totalVeiculos].preco);

                    totalVeiculos++;

                    // Salvar registros após adicionar um novo veículo
                    salvarRegistros(veiculos, totalVeiculos);

                    printf("Veiculo adicionado!\n");
                } else {
                    printf("Limite de veículos atingido.\n");
                }
                break;
            case 2:
                exibirRegistros(veiculos, totalVeiculos);
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
