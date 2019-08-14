#include <stdio.h>

int calculamdc(int x,int y){
	if(y==0) return x;
	return calculamdc(y,x%y);
}

int main(){
	int a1,b1,a2,b2,a,b,d;
	scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
	a=(a1*b2+a2*b1);
	b=(b1*b2);
	d=calculamdc(a,b);
	a=a/d;
	b=b/d;
	printf("%d %d\n",a,b);
	return 0;
}

