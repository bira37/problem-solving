#include <stdio.h>
#include <stdlib.h>

typedef struct _feira {
    char produto[200];
    double price;
}feira;

int main() {
    feira *lista;
    int i,aux,idas,quantidade,count,j,count2,k;
    double valor;
    char interesse[200];
    scanf("%d",&idas);
    for(i=0;i<idas;i++) {
        valor=0;
        scanf("%d",&count);
        lista=(feira*)malloc(count*sizeof(feira));
        for(j=0;j<count;j++) {
            scanf("%s %lf",lista[j].produto,&lista[j].price);
        }
        scanf("%d",&count2);
        for(j=0;j<count2;j++) {
            scanf("%s %d",interesse,&quantidade);
            for(k=0;k<count;k++) {
                if(strcmp(interesse,lista[k].produto)==0)
                    valor=valor+(lista[k].price*quantidade);
            }
        }
        printf("R$ %.2lf\n",valor);
        free(lista);
    }
    return 0;
}
