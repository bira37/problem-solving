#include <stdio.h>
 
int main() {
    int contadorNotas=0,flag=0;
    float nota,media,soma=0;
    while(flag != 2) {
        scanf("%f",&nota);
        if(nota>=0 && nota<=10) {
            contadorNotas+=1;
            soma+=nota;
            if(contadorNotas==2) {
                media=(soma*1.0)/2;
                printf("media = %.2f\n",media);
                soma=0;
                contadorNotas=0;
                printf("novo calculo (1-sim 2-nao)\n");
                scanf("%d",&flag);
                while(flag<1 || flag>2) {
                    printf("novo calculo (1-sim 2-nao)\n");
                    scanf("%d",&flag);
                }
            }
        }
        else {
            printf("nota invalida\n");
        }
    }
    return 0;
}
