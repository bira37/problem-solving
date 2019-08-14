#include <stdio.h>

int main() {
	int n[5],c[5],i,j,aux,menor,flag;
	for(i=0;i<=4;i++) {
		scanf("%d",&n[i]);
		c[i]=n[i];
	}
	if(n[1]>n[0]) flag=1;
	if(n[0]>n[1]) flag=0;
	for(i=0;i<=3;i++) {
		menor=i;
		for(j=i+1;j<=4;j++) {
			if(c[j]<c[menor])
				menor=j;
		}
		aux=c[i];
		c[i]=c[menor];
		c[menor]=aux;
	}
	if(flag==1) {
		if(n[0]==c[0] && n[1]==c[1] && n[2]==c[2] && n[3]==c[3] && n[4]==c[4]) {
			printf("C\n");
			return 0;
		}
		else {
			printf("N\n");
			return 0;
		}
	}
	if(flag==0) {
		if(n[0]==c[4] && n[1]==c[3] && n[2]==c[2] && n[3]==c[1] && n[4]==c[0]) {
			printf("D\n");
			return 0;
		}
		else {
			printf("N\n");
			return 0;
		}
	}
	return 0;
}
	

