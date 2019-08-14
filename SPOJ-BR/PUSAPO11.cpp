#include <stdio.h>

int main(){
	int npedra,nsapo,saposoma,saposub,pos,dist,i;
	scanf("%d %d",&npedra,&nsapo);
	int pedras[npedra];
	for(i=0;i<npedra;i++){
		pedras[i]=0;
	}
	for(i=0;i<nsapo;i++){
		scanf("%d %d",&pos,&dist);
		saposoma=pos-1;
		saposub=pos-1;
		pedras[pos-1]=1;
		saposoma=saposoma+dist;
		while(saposoma<npedra){
			pedras[saposoma]=1;
			saposoma=saposoma+dist;
		}
		saposub=saposub-dist;
		while(saposub>=0){
			pedras[saposub]=1;
			saposub=saposub-dist;
		}
	}
	for(i=0;i<npedra;i++){
		printf("%d\n",pedras[i]);
	}
	return 0;
}

