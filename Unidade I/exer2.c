/*
O CuiaBank é um banco digital criado por estudantes da UFMT, incluindo você, que ficou responsável por implementar uma função para controle de saques. O CuiaBank oferece para seus clientes um valor de saldo especial, que pode ser emprestado a juros.

A cada tentativa de saque, deve ser verificado se o valor a ser sacado é inferior ou igual à soma do saldo da conta com o saldo especial. Se a operação for efetivada, a função deve alterar os seguintes valores: saldo em conta, saldo especial utilizado (ambos armazenados na função principal). Ao final das operações, escreva na tela o extrato bancário. */
#include <stdio.h>
#include <stdlib.h>
void saque(float *sc, float *se)
{
    float valor;

    printf("\nDigite o valor a ser sacado: ");
    scanf("%f", &valor);

    if (valor <= (*sc + *se)) // se valor menor ou igual a (saldo_conta + saldo_especial)
    {
        *sc -= valor;
        if (*sc < 0) // se zerar o saldo em conta usa saldo especial
        {
            *se += *sc;
            *sc = 0;
        }
    }
    else
    {
        printf("Não eh possivel sacar esse valor. ");
    }
}
int main()
{
    float saldo_conta = 100, saldo_especial = 500;
    printf("\nsaldo em conta %.2f", saldo_conta);
    printf("\nsaldo especial %.2f", saldo_especial);

    saque(&saldo_conta, &saldo_especial);

    printf("\nsaldo em conta %.2f", saldo_conta);
    printf("\nsaldo especial %.2f", saldo_especial);

    return 0;
}