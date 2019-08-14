#include <stdio.h>

int main() {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b) {
		if(a>c) {
			printf("%d\n",a);
			return 0;
		}
		else if(a<c && b>c) {
			printf("%d\n",c);
			return 0;
		}
		else if(a<c && b<c) {
			printf("%d\n",b);
			return 0;
		}
	}
	else if(b<c) {
		if(b>a) {
			printf("%d\n",b);
			return 0;
		}
		else if(b<a && c>a) {
			printf("%d\n",a);
			return 0;
		}
		else if(b<a && c<a) {
			printf("%d\n",c);
			return 0;
		}
	}
	else if(c<a) {
		if(c>b) {
			printf("%d\n",c);
			return 0;
		}
		else if(c<b && a>b) {
			printf("%d\n",b);
			return 0;
		}
		else if(c<b && a<b) {
			printf("%d\n",a);
			return 0;
		}
	}
}
		

