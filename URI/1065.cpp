#include <stdio.h>
  
int main() {
    int num;
    int contadorPar=0,i;
    for(i=1;i<=5;i++) {
        scanf("%d",&num);
        if(num%2==0) {
            contadorPar++;
        }
    }
    printf("%d valores pares\n",contadorPar);
    return 0;
}
