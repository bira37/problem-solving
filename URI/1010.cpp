#include <stdio.h>
 
int main() {
    int numPeca,codigoPeca;
    float valorPeca,soma=0;
    scanf("%d %d %f\n",&codigoPeca,&numPeca,&valorPeca);
    soma+=(numPeca*valorPeca);
    scanf("%d %d %f",&codigoPeca,&numPeca,&valorPeca);
    soma+=(numPeca*valorPeca);
    printf("VALOR A PAGAR: R$ %.2f\n",soma);
    return 0;
}
