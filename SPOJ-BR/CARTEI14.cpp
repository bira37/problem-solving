#include <stdio.h>

int main(void) {
	int anterior=0,i,numerocasas,numeroencomendas,tempo=0,encomenda;
	int esq,dir,meio;
	scanf("%d %d",&numerocasas,&numeroencomendas);
	int casas[numerocasas];
	for(i=0;i<numerocasas;i++) scanf("%d",&casas[i]);
	for(i=0;i<numeroencomendas;i++){
		scanf("%d",&encomenda);
		esq=0;
		dir=numerocasas-1;
		while(esq<=dir){
			meio=(esq+dir)/2;
			if(casas[meio]==encomenda){
				tempo=tempo+abs(anterior-meio);
				anterior=meio;
				break;
			}
			else if(casas[meio]<encomenda) esq=meio+1;
			else dir=meio-1;
		}
	}
	printf("%d\n",tempo);
	return 0;
}
