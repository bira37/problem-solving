#include <stdio.h>
 
int main() {
    int ini,fim,res;
    scanf("%d %d",&ini,&fim);
    if(fim-ini==0) {
    	res=24;
    }
    else if(ini<24 && fim<ini) {
        res=(24-ini)+fim;
    }
    else res=fim-ini;
    printf("O JOGO DUROU %d HORA(S)\n",res);
    return 0;
}
