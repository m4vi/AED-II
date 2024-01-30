/*Maria Gláucia trabalha no departamento de recursos humanos de uma empresa que aumentará o salário dos seus funcionários. O programa lida com as seguintes informações:

código do departamento, representado por um número inteiro de 1 a 5;
salário do funcionário, representado por um número real;
Para funcionários dos departamentos 1 e 2, o aumento será de 22%. Para os funcionários do departamento 3, o aumento será de 17%. Para os funcionários do departamento 4 e 5, o aumento de salário será de 10%.

Considerando as informações anteriores, implemente um programa com uma função que altera o novo salário dos funcionários, considerando o salário atual, o reajuste e o departamento de atuação.

Ao final, imprima os valores de salário reajustados.*/

#include <stdio.h>
#include <stdlib.h>
void reajuste(int *codigo, float *salario)
{
    if ((*codigo == 1) || (*codigo == 2))
    {
        *salario *= 1.22;
    }
    else if (*codigo == 3)
    {
        *salario *= 1.17;
    }
    else if ((*codigo == 4) || (*codigo == 5))
    {
        *salario *= 1.10;
    }
}
int main()
{
    int codigo;
    float salario;

    printf("Digite o codigo do departamento: ");
    scanf("%d", &codigo);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);

    printf("Salario antigo: %.2f", salario);

    reajuste(&codigo, &salario);

    printf("\nSalario atual: %.2f", salario);

    return 0;
}