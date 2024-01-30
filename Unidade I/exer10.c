/*João implementou dois procedimentos em seu programa, um para verificar se um número é divisível por 3, outro para multiplicar o valor recebido por 10. Ambos os procedimentos recebem um número inteiro com parâmetro e não retornam valores, apenas exibem o resultado na tela.

João deseja criar um vetor com ponteiros para esses procedimentos para, em seguida, passar o vetor como parâmetro para um procedimento especial. Este último procedimento acionará os procedimentos recebidos como parâmetro para um conjunto de números inteiros determinados localmente.*/

#include <stdio.h>
#include <stdlib.h>

void divisivel_por_3(int num)
{
    if (num % 3 == 0)
    {
        printf("\nO numero é divisivel por 3");
    }
    else
    {
        printf("\nO numero nao eh divisivel por 3");
    }
}
void multiplicar_10(int num)
{
    printf("\nMultiplicar por 10: %d", num * 10);
}

void receber(void (*p[])(int))
{
    int vet[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("\nNum %d", vet[i]);
        p[0](vet[i]);
        (p[1])(vet[i]);
        printf("\n");
    }
    
}

int main()
{
    void (*p[2])(int) = {divisivel_por_3, multiplicar_10};
    receber(p);
    return 0;
}