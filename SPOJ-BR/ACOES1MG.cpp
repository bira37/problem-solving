#include <stdio.h>

int calculaCompra(int n,int k){
	if(n>k){
		if(n-n/2 <= k) return 2;
		else if(n/2 <= k) return 1+ calculaCompra(n-n/2,k);
		else return calculaCompra(n/2,k) + calculaCompra(n-n/2,k);
	}
	else return 1;
}

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k), n!=0 || k!=0){
		printf("%d\n",calculaCompra(n,k));
	}
	return 0;
}

