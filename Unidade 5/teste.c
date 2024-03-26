#include <stdio.h>
#include <string.h>
#define TAM 15
#define TAM_CHAR 50

typedef struct
{
    char nome[TAM_CHAR];
    int idade;
    int semestre;
} ALUNOS;

void bubbleSortNomes(ALUNOS f[], int tam)
{
    int ret;
    char palavra1[TAM_CHAR], palavra2[TAM_CHAR];
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            strcpy(palavra1, f[j].nome);
            strcpy(palavra2, f[j + 1].nome);
            ret = strcmp(palavra1, palavra2);
            if (ret > 0)
            {
                char auxc[TAM_CHAR];
                strcpy(auxc, f[j].nome);
                strcpy(f[j].nome, f[j + 1].nome);
                strcpy(f[j + 1].nome, auxc);

                // trocar idades corresponte a nome
                int aux = f[j].idade;
                f[j].idade = f[j + 1].idade;
                f[j + 1].idade = aux;

                // trocar semestres correspondente a nome
                aux = f[j].semestre;
                f[j].semestre = f[j + 1].semestre;
                f[j + 1].semestre = aux;
            }
        }
    }
}

int main(void)
{
    ALUNOS FAENG[TAM];

    strcpy(FAENG[0].nome, "Brenda Olegario");
    strcpy(FAENG[1].nome, "Nicolly Lagassi");
    strcpy(FAENG[2].nome, "Nayelly Cristina");
    strcpy(FAENG[3].nome, "Vitoria Paula");
    strcpy(FAENG[4].nome, "Gabrieli Garanhani");
    strcpy(FAENG[5].nome, "Jeasmine Megan");
    strcpy(FAENG[6].nome, "Katriely Piedade");
    strcpy(FAENG[7].nome, "Thaliny de Paula");
    strcpy(FAENG[8].nome, "Vitor Rafael");
    strcpy(FAENG[9].nome, "Raissa Irma");

    FAENG[0].idade = 33;
    FAENG[1].idade = 29;
    FAENG[2].idade = 25;
    FAENG[3].idade = 18;
    FAENG[4].idade = 19;
    FAENG[5].idade = 37;
    FAENG[6].idade = 45;
    FAENG[7].idade = 46;
    FAENG[8].idade = 56;
    FAENG[9].idade = 17;

    FAENG[0].semestre = 3;
    FAENG[1].semestre = 9;
    FAENG[2].semestre = 5;
    FAENG[3].semestre = 8;
    FAENG[4].semestre = 9;
    FAENG[5].semestre = 7;
    FAENG[6].semestre = 5;
    FAENG[7].semestre = 4;
    FAENG[8].semestre = 6;
    FAENG[9].semestre = 1;
    int iTamanho = 10;

    bubbleSortNomes(FAENG, iTamanho);

    for (int i = 0; i < iTamanho; i++)
    {
        printf("posicao [%d], Nome: %s, Idade: %d, Semestre: %d\n", i, FAENG[i].nome, FAENG[i].idade, FAENG[i].semestre);
    }

    return 0;
}