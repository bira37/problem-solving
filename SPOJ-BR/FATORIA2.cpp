#include <stdio.h>

int fat(int a){
	if(a>1) return a*fat(a-1);
	return a;
}

int main(){
	int a;
	scanf("%d",&a);
	if(a==0) printf("%d\n",a+1);
	else printf("%d\n",fat(a));
	return 0;
}

