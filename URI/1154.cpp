#include <stdio.h>
 
int main() {
    int idade,somaIdade=0,contadorEntrada=0;
    scanf("%d",&idade);
    while(idade>=0) {
        somaIdade+=idade;
        contadorEntrada+=1;
        scanf("%d",&idade);
    }
    printf("%.2f\n",(somaIdade*1.0)/contadorEntrada);
    return 0;
}
