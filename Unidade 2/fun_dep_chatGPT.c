#include <stdio.h>
#include <string.h>

#define MAX_DEPARTAMENTOS 10
#define MAX_FUNCIONARIOS 50

// Definição da estrutura para representar um departamento
typedef struct
{
    char nome[50];
    int codigo;
} Departamento;

// Definição da estrutura para representar um funcionário
typedef struct
{
    char nome[50];
    int codigo;
    int deptoIndex; // Índice do departamento no vetor de departamentos
} Funcionario;

// Função para cadastrar um novo departamento
void cadastrarDepartamento(Departamento departamentos[], int *numDeptos)
{
    if (*numDeptos >= MAX_DEPARTAMENTOS)
    {
        printf("Limite máximo de departamentos atingido.\n");
        return;
    }

    printf("Digite o nome do departamento: ");
    scanf("%s", departamentos[*numDeptos].nome);
    printf("Digite o código do departamento: ");
    scanf("%d", &departamentos[*numDeptos].codigo);

    (*numDeptos)++;
}

// Função para listar informações de um departamento
void listarDepartamento(const Departamento *depto)
{
    printf("Nome do departamento: %s\n", depto->nome);
    printf("Código do departamento: %d\n", depto->codigo);
}

// Função para cadastrar um novo funcionário
void cadastrarFuncionario(Funcionario funcionarios[], int *numFuncionarios, Departamento departamentos[], int numDeptos)
{
    if (*numFuncionarios >= MAX_FUNCIONARIOS)
    {
        printf("Limite máximo de funcionários atingido.\n");
        return;
    }

    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionarios[*numFuncionarios].nome);
    printf("Digite o código do funcionário: ");
    scanf("%d", &funcionarios[*numFuncionarios].codigo);

    // Lista os departamentos disponíveis para o funcionário escolher
    printf("Departamentos disponíveis:\n");
    for (int i = 0; i < numDeptos; i++)
    {
        printf("%d. %s\n", i + 1, departamentos[i].nome);
    }

    // Seleciona o departamento ao qual o funcionário está vinculado
    printf("Digite o número correspondente ao departamento: ");
    scanf("%d", &funcionarios[*numFuncionarios].deptoIndex);

    if (funcionarios[*numFuncionarios].deptoIndex < 0 || funcionarios[*numFuncionarios].deptoIndex >= numDeptos)
    {
        printf("Escolha de departamento inválida.\n");
        return;
    }

    (*numFuncionarios)++;
}

// Função para listar informações de um funcionário
void listarFuncionario(const Funcionario *func, const Departamento *departamentos)
{
    printf("Nome do funcionário: %s\n", func->nome);
    printf("Código do funcionário: %d\n", func->codigo);
    printf("Departamento do funcionário:\n");
    listarDepartamento(&departamentos[func->deptoIndex]);
}

// Função para atualizar as informações de um departamento
void atualizarDepartamento(Departamento departamentos[], int numDeptos)
{
    printf("Departamentos disponíveis para atualização:\n");
    for (int i = 0; i < numDeptos; i++)
    {
        printf("%d. %s\n", i + 1, departamentos[i].nome);
    }

    int escolha;
    printf("Digite o número correspondente ao departamento que deseja atualizar: ");
    scanf("%d", &escolha);

    if (escolha <= 0 || escolha > numDeptos)
    {
        printf("Escolha inválida.\n");
        return;
    }

    printf("Digite o novo nome do departamento: ");
    scanf("%s", departamentos[escolha - 1].nome);
    printf("Digite o novo código do departamento: ");
    scanf("%d", &departamentos[escolha - 1].codigo);
}

// Função para atualizar o departamento de todos os funcionários associados
void atualizarFuncionariosComDepartamento(Funcionario funcionarios[], int numFuncionarios, Departamento departamentos[], int numDeptos)
{
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (funcionarios[i].deptoIndex >= 0 && funcionarios[i].deptoIndex < numDeptos)
        {
            // Atualiza o departamento do funcionário
            listarFuncionario(&funcionarios[i], departamentos);
        }
    }
}
int main()
{
    Departamento departamentos[MAX_DEPARTAMENTOS];
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numDeptos = 0;
    int numFuncionarios = 0;

    // Cadastro de departamentos
    printf("### Cadastro de Departamentos ###\n");
    for (int i = 0; i < 2; i++)
    { // Cadastro de dois departamentos para exemplo
        cadastrarDepartamento(departamentos, &numDeptos);
    }

    // Cadastro de funcionários
    printf("\n### Cadastro de Funcionários ###\n");
    for (int i = 0; i < 3; i++)
    { // Cadastro de três funcionários para exemplo
        cadastrarFuncionario(funcionarios, &numFuncionarios, departamentos, numDeptos);
    }

    // Exibição das informações cadastradas
    printf("\n### Informações Cadastradas ###\n");
    printf("\n### Departamentos ###\n");
    for (int i = 0; i < numDeptos; i++)
    {
        listarDepartamento(&departamentos[i]);
    }
    printf("\n### Funcionários ###\n");
    for (int i = 0; i < numFuncionarios; i++)
    {
        listarFuncionario(&funcionarios[i], departamentos);
    }

    // Atualização de departamento
    printf("\n### Atualização de Departamento ###\n");
    atualizarDepartamento(departamentos, numDeptos);

    // Atualização dos funcionários associados ao departamento
    printf("\n### Atualização de Funcionários Associados ###\n");
    atualizarFuncionariosComDepartamento(funcionarios, numFuncionarios, departamentos, numDeptos);

    // Exibição das informações atualizadas
    printf("\n### Informações Atualizadas ###\n");
    printf("\n### Departamentos ###\n");
    for (int i = 0; i < numDeptos; i++)
    {
        listarDepartamento(&departamentos[i]);
    }
    printf("\n### Funcionários ###\n");
    for (int i = 0; i < numFuncionarios; i++)
    {
        listarFuncionario(&funcionarios[i], departamentos);
    }

    return 0;
}