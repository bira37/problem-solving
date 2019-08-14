#include <stdio.h>

int main(void) {
	long long i,esq,dir,c,t,k,x,y,dist,meio;
	scanf("%lld %lld",&c,&t);
	long long circulo[c];
	for(i=0;i<c;i++){
		scanf("%lld",&k);
		circulo[i]=k*k;
	}
	k=0;
	for(i=0;i<t;i++){
		esq=0;
		dir=c-1;
		scanf("%lld %lld",&x,&y);
		dist=x*x + y*y;
		while(esq<=dir){
			meio=(esq+dir)/2;
			if(circulo[meio]==dist){
				k=k+(c-meio);
				break;
			}
			else if(dist < circulo[meio]) dir=meio-1;
			else esq=meio+1;
		}
		if(dir < esq && esq < c) k=k+(c-esq);
	}
	printf("%lld\n",k);
	return 0;
}
