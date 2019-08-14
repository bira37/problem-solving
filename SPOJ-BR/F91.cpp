#include <stdio.h>

int f91(int n){
	if(n<=100) f91(f91(n+11));
	else return n-10;
}

int main(void) {
	int n,x;
	while(scanf("%d",&n),n!=0){
		x=f91(n);
		printf("f91(%d) = %d\n",n,x);
	}
	return 0;
}
