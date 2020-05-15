#include <stdio.h>
 
int main() {
    int lim1,lim2,i,aux;
    scanf("%d %d",&lim1,&lim2);
    if(lim1>lim2) { //caso o segundo numero da entrada seja menor que o primeiro, eles sao trocados
            aux=lim1;
            lim1=lim2;
            lim2=aux;
    }
    for(i=lim1+1;i<lim2;i++) {
        if(i%5==3 || i%5==2)
            printf("%d\n",i);
    }
    return 0;
}
