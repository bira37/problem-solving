#include <stdio.h>
   
int main() {
    char nome[200];
    double salarioNormal,totalVendas,totalSalario;
    scanf("%s\n%lf\n%lf",&nome,&salarioNormal,&totalVendas);
    totalSalario=salarioNormal+(totalVendas*15.0)/100; //calcula o salário com bônus
    printf("TOTAL = R$ %.2lf\n",totalSalario);
    return 0;
}
