#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef enum
{
    TEMPERATURA,
    LUMINOSIDADE,
    MOVIMENTO
} TipoSensor;

typedef struct
{
    TipoSensor tipo;
    union
    {
        float temperatura;
        float luminosidade;
        bool movimento;
    } dados;
} Sensor;

void cadastro(Sensor *sensores, int *totalSensores)
{
    printf("\n0 - Temperatura");
    printf("\n1 - Luminosidade");
    printf("\n2 - Movimento");
    int tipo;
    scanf("%d", &tipo);

    if (tipo < 1 || tipo > 3)
    {
        printf("Opção inválida.\n");
        return;
    }

    Sensor novoSensor;

    switch (tipo)
    {
    case 0: // temperatura
        printf("Digite a temperatura em graus Celsius: ");
        scanf("%f", &novoSensor.dados.temperatura);
        break;
    case 1: // luminosidade
        printf("Digite a luminosidade em porcentagem: ");
        scanf("%f", &novoSensor.dados.luminosidade);
        break;
    case 2: // movimento
        printf("Movimento detectado? (1 para Sim, 0 para Não): ");
        scanf("%d", &novoSensor.dados.movimento);
    default:
        break;
    }
}
int main()
{
    Sensor S[TAM];

    int pos = 0;
    int opcao;

    do
    {

        printf("\n-1 - sair\n");
        printf(" 1 - cadastros\n");
        printf(" 2 - listar \n");
        printf(" Digite uma opcao: ");
        scanf("%d", &opcao);

        // int pos_aux;
        switch (opcao)
        {
        case 1:
            if (pos < TAM)
            {
                cadastro(S, &pos);
            }
            else
            {
                printf("esta cheio\n");
            }
            break;
        case 2:
            exibirSensores(sensores, totalSensores);

            break;
        case -1:
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != -1);

    return 0;
}
