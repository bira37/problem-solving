#include <stdio.h>

int calculaValor(float valorTotal,int numero,int quantidade) { //funçao calcula o valor total
    if(numero==1)
        valorTotal= 4.00*quantidade;
    else if(numero==2)
        valorTotal= 4.50*quantidade;
    else if(numero==3)
        valorTotal= 5.00*quantidade;
    else if(numero==4)
        valorTotal= 2.00*quantidade;
    else if(numero==5)
        valorTotal= 1.50*quantidade;
   	printf("Total: R$ %.2f\n",valorTotal);
	return 0;
}

int main() {
    int numero,quantidade;
    float valorTotal;
    scanf("%d %d",&numero,&quantidade);
    calculaValor(valorTotal,numero,quantidade); //calcula e imprime o valor total do lanche
    return 0;
}
