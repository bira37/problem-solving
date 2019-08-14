#include <stdio.h>

int main() {
	int pessoas,conta,soma=0,teste,i;
	scanf("%d",&pessoas);
	for(i=0;i<pessoas;i++) {
		scanf("%d",&conta);
		soma=soma+conta;
	}
	scanf("%d",&teste);
	if(soma==teste) {
		printf("Acertou\n");
	}
	else printf("Errou\n");
	return 0;
}

