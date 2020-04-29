#include <stdio.h>
 
int main() {
    int numeroFuncionario, tempoTrabalho;
    float salarioHora;
    scanf("%d\n%d\n%f",&numeroFuncionario,&tempoTrabalho,&salarioHora);
    printf("NUMBER = %d\nSALARY = U$ %.2f\n",numeroFuncionario,tempoTrabalho*salarioHora);
    return 0;
}
