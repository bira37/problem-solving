#include <stdio.h>

int main(void) {
	long long n,teste=1,x,i;
	while(scanf("%lld",&n), n!=0){
		x=1;
		for(i=0;i<n;i++) x*=2;
		printf("Teste %lld\n%lld\n\n",teste++,x-1);
	}
	return 0;
}
