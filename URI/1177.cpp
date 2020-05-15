#include <stdio.h>
  
int main() {
    int vet[1000],limite,i=0,cont=0;
    scanf("%d",&limite);
    while(i<1000) {
        if(cont<limite) {
            vet[i]=cont;
            cont++;
        }
        if(cont>=limite) {
            cont=0;
        }
        printf("N[%d] = %d\n",i,vet[i]);
    i++;
    }
    return 0;
}
