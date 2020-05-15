#include <stdio.h>
#include <stdlib.h>
int quick(int *numero,int ini,int fim){
    int pivo;
    if(fim>ini) {
        pivo=part(numero,ini,fim);
        quick(numero,ini,pivo-1);
        quick(numero,pivo+1,fim);
    }
    return 0;
}
int part(int *numero,int ini,int fim) {
    int esq,dir,pivo,aux;
    esq=ini;
    dir=fim;
    pivo=numero[ini];
    while(esq<dir) {
        while(numero[esq]<=pivo)
            esq++;
        while(numero[dir]>pivo)
            dir--;
        if(esq<dir) {
            aux=numero[esq];
            numero[esq]=numero[dir];
            numero[dir]=aux;
        }
    }
    numero[ini]=numero[dir];
    numero[dir]=pivo;
    return(dir);
}
int main() {
    int *numero;
    int i,j,tamanho,meio=0,menor,esq,dir,aux;
    scanf("%d",&tamanho);
    numero=(int*)malloc(tamanho*sizeof(int));
    for(i=0;i<tamanho;i++) {
            scanf("%d",&numero[i]);
            if(numero[i]%2==0) meio++;
    }
    esq=0;
    dir=tamanho-1;
    while(esq<=dir) {
        while(numero[esq]%2==0)
            esq++;
        while(numero[dir]%2==1)
            dir--;
        if(esq<=dir) {
            aux=numero[esq];
            numero[esq]=numero[dir];
            numero[dir]=aux;
            esq++;
            dir--;
        }
    }
    quick(numero,0,meio-1);
    quick(numero,meio,tamanho-1);
    for(i=0;i<meio;i++) {
        printf("%d\n",numero[i]);
    }
    for(i=tamanho-1;i>=meio;i--) {
        printf("%d\n",numero[i]);
    }
    free(numero);
    return 0;
}
