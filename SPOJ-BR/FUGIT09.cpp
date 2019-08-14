#include <stdio.h>

int main() {
	char referencia;
	long long x=0,y=0,dist,distmax,registro,i,flag=0;
	scanf("%lld %lld",®istro,&distmax);
	for(i=0;i<registro;i++) {
		scanf("%c %lld\n",&referencia,&dist);
		if(referencia=='N') {
			y=y+dist;
		}
		else if(referencia=='S') {
			y=y-dist;
		}
		else if(referencia=='L') {
			x=x+dist;
		}
		else if(referencia=='O') {
			x=x-dist;
		}
		if(flag==0 && (x*x)+(y*y)>distmax*distmax) {
			flag=1;
		}
	}
	printf("%lld\n",flag);
	return 0;
}
	
			
	

