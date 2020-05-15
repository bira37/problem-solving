#include <stdio.h>
#include <string.h>

void calculaHash(char c,int it,int pos, int *soma){
    (*soma)=(*soma)+it+pos+(c-'A');
}
 
int main() {
    int testes,i,n,soma,k,tamanho,j;
	scanf("%d",&testes);
    for(k=0;k<testes;k++){
        scanf("%d",&n);
        soma=0;
        char palavra[50];
        for(i=0;i<n;i++){
            scanf("%s",palavra);
            tamanho=strlen(palavra);
            for(j=0;j<tamanho;j++) calculaHash(palavra[j],i,j,&soma);
        }
        printf("%d\n",soma);
    }
    return 0;
}
