#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void escreverMensagem(FILE *arquivo, char *frase, int pulo) {
    int i;
    for (i = 0; i < strlen(frase); i += pulo) {
        fputc(frase[i], arquivo);
    }
    fputc('\n', arquivo);
}

void lerMensagem(FILE *arquivo, int pulo) {
    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        printf("%c", caractere);
        fseek(arquivo, pulo - 1, SEEK_CUR);
    }
    printf("\n");
}

int main() {
    int opcao, pulo;
    char frase[MAX_LENGTH];

    FILE *arquivo;

    while (1) {
        printf("Selecione uma opcao:\n");
        printf("1. Escrever mensagem\n");
        printf("2. Ler mensagem\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        }

        if (opcao == 1) {
            printf("Digite a frase (ate 100 caracteres): ");
            getchar(); // Limpar o buffer do teclado
            fgets(frase, MAX_LENGTH, stdin);

            printf("Digite um numero inteiro entre 1 e 5: ");
            scanf("%d", &pulo);

            arquivo = fopen("mensagem.txt", "a");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }

            escreverMensagem(arquivo, frase, pulo);

            fclose(arquivo);
        } else if (opcao == 2) {
            printf("Digite um numero inteiro entre 1 e 5: ");
            scanf("%d", &pulo);

            arquivo = fopen("mensagem.txt", "r");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }

            lerMensagem(arquivo, pulo);

            fclose(arquivo);
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
