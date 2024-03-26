/*Os algoritmos de ordenação utilizam uma variável chave para ordenar um vetor. Em geral, para fins didáticos, trabalha-se com uma variável do tipo int como este atributo. Escolha, dentre os algoritmos de ordenação apresentados na aula anterior, um para adaptar. O algoritmo, após o seu ajuste, deve ser capaz de ordenar strings.

Entrada	Saída
RONDONOPOLIS	AMORINOPOLIS
CUIABA	CUIABA
AMORINOPOLIS	DIORAMA
DIORAMA	RONDONOPOLIS*/
#include <stdio.h>
#include <string.h>

void trocar(char *palavra1, char *palavra2)
{
    char aux[13];

    strcpy(aux, palavra1);
    strcpy(palavra1, palavra2);
    strcpy(palavra2, aux);
}

void bubbleSort(char palavras[4][13], int tam)
{
    int ret;
    char palavra1[13], palavra2[13];
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            strcpy(palavra1, palavras[j]);
            strcpy(palavra2, palavras[j+1]);
            ret = strcmp(palavra1, palavra2);
            if (ret > 0)
            {
                trocar(palavras[j], palavras[j+1]);
            }
        }
    }
}

int main(void)
{
    char Cidades[4][13] = {"CAMOMILA", "ZEBRA", "ASSUNCAO", "DIONISIO"};
    int iTamanho = 4;

    bubbleSort(Cidades, iTamanho);

    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", Cidades[i]);
    }

    return 0;
}

/* strcpy(string_destino,string a ser copiada)
char cuiaba[15];
char amorinopolis[15];
int ret;

strcpy(cuiaba, "CUIABA");
strcpy(amorinopolis, "IMORINOPOLIS");

ret = strcmp(amorinopolis, cuiaba);

if (ret < 0)
{
    printf("%s vem antes de %s", amorinopolis, cuiaba);
}
else if (ret > 0)
{
    printf("%s vem antes de %s", cuiaba, amorinopolis);
}
else
{
    printf("str1 EH IGUAL QUE str2");
}

return 0;
}

// strcnp comparar
// strcpy copiar
*/