#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    char nome[100];
    int codigo;
} Departamento;

typedef struct
{
    char nome[100];
    int codigo;
    Departamento *dep;
} Funcionario;

int main()
{
    Departamento **Dep_vet;
    Funcionario *Func_vet;

    Dep_vet = (Departamento**)calloc(4, sizeof(Departamento**));
    Func_vet = (Funcionario *)calloc(4, sizeof(Funcionario));

    Dep_vet[0] = (Departamento *)malloc(sizeof(Departamento));

    Dep_vet[0] = {"Financeiro", 0};
    // Func_vet[0] = {"Maria", 0, &Dep_vet[0]};
    return 0;
}
