#include <stdio.h>
  
int main() {
    int lim1,lim2,num,soma=0,i,aux;
    scanf("%d %d",&lim1,&lim2);
    while(lim1>0 && lim2>0) {
        if(lim1>lim2) { //caso o segundo numero da entrada seja menor que o primeiro, eles sao trocados
            aux=lim1;
            lim1=lim2;
            lim2=aux;
        }
        for(i=lim1;i<=lim2;i++) {
            printf("%d ",i);
            soma+=i;
            if(i==lim2)
                printf("Sum=%d\n",soma);
        }
        scanf("%d %d",&lim1,&lim2);
        soma=0;
    }
    return 0;
}
