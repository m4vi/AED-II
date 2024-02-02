/*Roberval, aquele um estudante de Controle e Automação que queria criar um sistema 
controle de luzes de uma casa, está de volta. Agora, ele pretende melhorar o sistema 
desenvolvido, colocando uma “memória”, que considera o estado da lâmpada após a 
execução anterior do programa. 
Por exemplo: se o programa anterior terminou com a lâmpada ligada, em uma 
nova execução, essa informação deve ser considerada. */

#include <stdio.h>
#include <stdlib.h>

void ligar(int *luz)
{
    *(luz) = 1;
    printf("Luz %d\n", *luz);
}
void desligar(int *luz)
{
    *(luz) = 0;
    printf("Luz %d\n", *luz);
}
void interruptor(int *lampada, void (*pon_desligar)(int*), void (*pon_ligar)(int*))
{
    if (*lampada == 0) // se estiver desligada
    {
        pon_ligar(lampada);
    }
    else if (*(lampada) == 1) // se a luz estiver ligada
    {
        pon_desligar(lampada);
    }
}
int main(void)
{
    int luz = 1;
    int *pontSimples = &luz;
    // 0 apagada
    // 1 acesa

    void (*ponteiro_ligar)(int*);
    ponteiro_ligar = ligar;

    void (*ponteiro_desligar)(int*);
    ponteiro_desligar = desligar;

    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);
    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);
    interruptor(pontSimples, ponteiro_desligar, ponteiro_ligar);
    return 0;
}