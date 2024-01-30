/*Roberval é um estudante de Controle e Automação que deseja criar um sistema controle de luzes de uma casa. Para começar, ele pretende criar procedimentos para ligar e desligar as luzes.

Um terceiro procedimento, que simula um interruptor, recebe os endereços de memória dos procedimentos ligar e desligar. Se a lâmpada estava desligada, o procedimento deve ligá-la quando acionada. Da mesma forma, se ela estivesse desligada, o procedimento deveria desligar a luz.

O procedimento interruptor deve acionar os anteriores usando ponteiros.*/

#include <stdio.h>

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