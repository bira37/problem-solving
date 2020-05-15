#include <stdio.h>
 
int main() {
    int vet[1000],i,tamanho,menor=1000000,posicao=0;
    scanf("%d",&tamanho);
    for(i=0;i<=tamanho-1;i++) {
        scanf("%d",&vet[i]);
        if(vet[i]<menor) {
            menor=vet[i];
            posicao=i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n",menor,posicao);
    return 0;
}
