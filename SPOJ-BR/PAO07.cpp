#include <stdio.h>

int checaTamanho(int *v,int particao,int pessoas,int paes){
	int count=0;
	int i;
	for(i=0;i<paes;i++) count+=v[i]/particao;
	if(count>=pessoas) return 1;
	else return 0;
}

int main(void) {
	int i,esq=0,dir=10000,resp,n,t,meio;
	scanf("%d %d",&n,&t);
	int pao[t];
	for(i=0;i<t;i++) scanf("%d",&pao[i]);
	while(esq <= dir){
		meio=(esq+dir)/2;
		if(checaTamanho(pao,meio,n,t)){
			esq=meio+1;
			resp=meio;
		}
		else dir=meio-1;
	}
	printf("%d\n",resp);
}

