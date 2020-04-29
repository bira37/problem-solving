#include <stdio.h>
 
int main() {
    double cedulas[12]={100.0,50.0,20.0,10.0,5.0,2.0,1.0,0.50,0.25,0.10,0.05,0.01};
    int cont[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    double valor;
	int i;
    scanf("%lf",&valor);
    for(i=0;i<=11;i++){
        while(valor>=cedulas[i]){
            valor-=cedulas[i];
            cont[i]++;
        }
    }
	printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n",cont[0]);
    printf("%d nota(s) de R$ 50.00\n",cont[1]);
    printf("%d nota(s) de R$ 20.00\n",cont[2]);
    printf("%d nota(s) de R$ 10.00\n",cont[3]);
    printf("%d nota(s) de R$ 5.00\n",cont[4]);
    printf("%d nota(s) de R$ 2.00\n",cont[5]);
	printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",cont[6]);
	printf("%d moeda(s) de R$ 0.50\n",cont[7]);
	printf("%d moeda(s) de R$ 0.25\n",cont[8]);
	printf("%d moeda(s) de R$ 0.10\n",cont[9]);
	printf("%d moeda(s) de R$ 0.05\n",cont[10]);
	printf("%d moeda(s) de R$ 0.01\n",cont[11]);
    return 0;
}
