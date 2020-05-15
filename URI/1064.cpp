#include <stdio.h>
 
int main() {
    float num,somaNum=0;
    int contadorPos=0,i;
    for(i=1;i<=6;i++) {
        scanf("%f",&num);
        if(num>0) {
            contadorPos++;
            somaNum+=num;
        }
    }
    printf("%d valores positivos\n%.1f\n",contadorPos,(somaNum*1.0)/contadorPos);
    return 0;
}
