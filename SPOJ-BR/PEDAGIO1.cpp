#include <stdio.h>

int main()
{
	int c,d,k,v,soma;
	scanf("%d %d\n%d %d",&c,&d,&k,&v);
	soma= ((c/d)*v) + (k*c);
	printf("%d\n",soma);
	return(0);
}

