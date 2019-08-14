#include <stdio.h>

int main() {
	int x1,x2,x3;
	scanf("%d %d %d",&x1,&x2,&x3);
	while(x1+x2+x3!=0) {
		printf("%d\n",x1*x2*x3);
		scanf("%d %d %d",&x1,&x2,&x3);
	}
	return 0;
}

