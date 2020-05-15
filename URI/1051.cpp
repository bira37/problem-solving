#include <stdio.h>
 
int main() {
    float x,soma=0;
    scanf("%f",&x);
    if(x<=2000.00) printf("Isento\n");
	else {
		if(x>4500) {
			soma+=(x-4500)*0.28;
			x=x-(x-4500);
		}
		if(x>3000) {
			soma+=(x-3000)*0.18;
			x=x-(x-3000);
		}
		if(x>2000) {
			soma+=(x-2000)*0.08;
			x=x-(x-2000);
		}
		printf("R$ %.2f\n",soma);
	}
    return 0;
}
