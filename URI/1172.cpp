#include <stdio.h>
 
int main() {
    int vet[10],i;
    for(i=0;i<=9;i++) {
        scanf("%d",&vet[i]);
        if(vet[i]<=0)
            vet[i]=1;
    }
    for(i=0;i<=9;i++) {
        printf("X[%d] = %d\n",i,vet[i]);
    }
    return 0;
}
