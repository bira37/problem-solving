#include <stdio.h>
#include <math.h>

int main() {
	int num,gera,tempo,i,pos,resp;
	double maior;
	scanf("%d",&num);
	scanf("%d %d",&gera,&tempo);
	maior= tempo*log10(gera);
	pos=0;
	resp=0;
	for(i=1;i<num;i++) {
		pos++;
		scanf("%d %d",&gera,&tempo);
		if(maior < tempo*log10(gera)) {
			maior=tempo*log10(gera);
			resp=pos;
		}
	}
	printf("%d\n",resp);
	return 0;
}

	
	

