#include <stdio.h>
#include <math.h>

int main(void) {
	long long n,i;
	scanf("%lld",&n);
	if(n<0) n=n*(-1);
	long double raiz=sqrt(n);
	if(n==2) printf("sim\n");
	else if(n==1 || n%2 == 0) printf("nao\n");
	else {
		for(i=3;i<=raiz;i+=2)
			if(n%i==0){
				printf("nao\n");
				goto ret;
			}
		printf("sim\n");
	}
ret:return 0;
}
