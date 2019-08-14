#include <stdio.h>

int main()
{
	int a1,a2,b1,b2,res;
	scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
	res= abs(b1-a1)+abs(b2-a2);
	printf("%d\n",res);
	return(0);
}

