#include <stdio.h>
       
int main() {
    int i,j,cont=0;
    float mat[12][12],soma=0;
    char operacao;
    scanf("%c",&operacao);
    for(i=0;i<=11;i++) {
        for(j=0;j<=11;j++) {
            scanf("%f",&mat[i][j]);
        }
    }
    for(i=1;i<=5;i++) {
        for(j=11;j>11-i;j--) {
            soma+=mat[i][j];
            cont++;
        }
    }
    for(i=6;i<=10;i++) {
        for(j=11;j>=i+1;j--) {
            soma+=mat[i][j];
            cont++;
        }
    }
    if(operacao=='S')
        printf("%.1f\n",soma);
    else if(operacao=='M')
        printf("%.1f\n",soma/cont);
    return 0;
}
