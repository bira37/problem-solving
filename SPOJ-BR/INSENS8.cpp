#include <stdio.h>

int main() {
	int x1,x2,y1,y2,i,soma=0,objetos,xsoma,ysoma;
	scanf("%d",&objetos);
	for(i=0;i<objetos;i++) {
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		xsoma=abs(x2-x1);
		ysoma=abs(y2-y1);
		soma=soma+(xsoma*xsoma)+(ysoma*ysoma);
	}
	printf("%d\n",soma);
	return 0;
}
	

