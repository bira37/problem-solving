#include <stdio.h>

int main() {
	int in1,in2;
	scanf("%d %d",&in1,&in2);
	if(in1==1) {
		if(in2==1) {
			printf("A\n");
		}
		else if(in2==0) {
			printf("B\n");
		}
	}
	else if(in1==0) {
		printf("C\n");
	}
	return 0;
}

