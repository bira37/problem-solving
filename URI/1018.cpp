#include <stdio.h>
 
int main() {
    int cedulas[7]={100,50,20,10,5,2,1};
    int cont[7]={0,0,0,0,0,0,0};
    int valor1,valor,i;
    scanf("%d",&valor1);
    valor=valor1;
    for(i=0;i<=6;i++){
        while(valor>=cedulas[i]){
            valor-=cedulas[i];
            cont[i]++;
        }
    }
    printf("%d\n",valor1);
    printf("%d nota(s) de R$ 100,00\n",cont[0]);
    printf("%d nota(s) de R$ 50,00\n",cont[1]);
    printf("%d nota(s) de R$ 20,00\n",cont[2]);
    printf("%d nota(s) de R$ 10,00\n",cont[3]);
    printf("%d nota(s) de R$ 5,00\n",cont[4]);
    printf("%d nota(s) de R$ 2,00\n",cont[5]);
    printf("%d nota(s) de R$ 1,00\n",cont[6]);
    return 0;
}
