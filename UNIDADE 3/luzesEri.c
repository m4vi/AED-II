
#include <stdio.h>
#include <stdlib.h>

void off(int *ptrvet){
        *ptrvet=0;
        *(ptrvet+1)=0;
        *(ptrvet+2)=0;
}
void on(int *ptrvet){
        *ptrvet=1;
        *(ptrvet+1)=1;
        *(ptrvet+2)=1;

}
void Iinterruptor(void (*pontA)(int*), void (*pontB)(int*), int *vet){
    if(*vet==0){
        pontA(vet);
}
    else{
        pontB(vet);
}
}
int main()
{
    FILE *arquivo = fopen("aula.txt", "r+");
    int interruptor;
    int vetluz[3];
    if(!arquivo){
        printf("Erro ao abrir arquivo para escrita.\n");
        return 1;
    }
    if(fscanf(arquivo, "%d %d %d", &vetluz[0], &vetluz[1], &vetluz[2]) == EOF){
    vetluz[0]=0;
    vetluz[1]=0;
    vetluz[2]=0;
    }
    else{
        fscanf(arquivo, "%d %d %d", vetluz[0], vetluz[1], vetluz[2]);
    }
    printf("luz\t%d",vetluz[1]);
    do{
    printf("\n");
    printf("deseja apertar o iinterruptor? 1: sim\n");
    scanf("%d",&interruptor);
    if(interruptor==1){
    Iinterruptor(on, off, vetluz);
    printf("\n");
    printf("luz\t%d",vetluz[1]);
    }
    }while(interruptor!=0);
    fprintf(arquivo, "%d %d %d", vetluz[0], vetluz[1], vetluz[2] );
    return 0;
}
