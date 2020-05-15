#include <stdio.h>
 
int main() {
    int vet[20],fim,i,aux;
   	for(i=0;i<=19;i++) {
		scanf("%d",&vet[i]);
	}
    fim=19;
    for(i=0;i<=9;i++) {
        aux=vet[i];
        vet[i]=vet[fim];
        vet[fim]=aux;
        fim--;
    }
    for(i=0;i<=19;i++) {
        printf("N[%d] = %d\n",i,vet[i]);
    }
    return 0;
}
