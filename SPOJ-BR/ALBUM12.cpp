#include <stdio.h>

int main() {
	int x,y,x1,y1,x2,y2;
	scanf("%d %d\n%d %d\n%d %d",&x,&y,&x1,&y1,&x2,&y2);
	if(x1+x2<=x && y1<=y && y2<=y)
		printf("S\n");
	else if(x1+y2<=y && y1<=x && x2<=x)
		printf("S\n");
	else if(y1+y2<=y && x1<=x && x2<=x)
		printf("S\n");
	else if(y1+y2<=x && x1<=y && x2<=y)
		printf("S\n");
	else if(x2+y1<=y && x1<=x && y2<=x)
		printf("S\n");
	else if(x1+x2<=y && y1<=x && y2<=x)
		printf("S\n");
	else if(x1+x2<=y && y1<=x && y2<=x)
		printf("S\n");
	else if(x1+y2<=x && x2<=y && y1<=y)
		printf("S\n");
	else if(x2+y1<=x && x1<=y && y2<=y)
		printf("S\n");
	else if(x1+x2<=x && y1<=y && y2<=y)
		printf("S\n");
	else printf("N\n");
	return 0;
}

