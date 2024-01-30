/*Analise o fragmento de código a seguir:

int a = 17;
int *ptr1 = &a;
void **ptr2 = (void **) &ptr1;
Qual operação pode ser feita para, a partir de ptr2, se chegar ao valor da variável a?*/

#include <stdio.h>

int main(void)
{
    int a = 17;
    int *ptr1 = &a;
    void **ptr2 = (void **) &ptr1;

    
    printf("Valor de A: %d\n", a);
    printf("Valor de A: %d\n", *ptr1);
    printf("Valor de A: %d\n", **(int**)ptr2);
    

    return 0;
}