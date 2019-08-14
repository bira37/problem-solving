#include <stdio.h>

int main(){
	int i,j,l,c,costa=0;
	char mapa[1000][1000];
	scanf("%d %d",&l,&c);
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			scanf("%c",&mapa[i][j]);
			if(mapa[i][j]=='\n') scanf("%c",&mapa[i][j]);
			if(mapa[i][j]=='#') costa++;
		}
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			if(mapa[i][j]=='#'){
				if(i>0 && i<999 && j>0 && j<999){
					if(mapa[i-1][j]=='#' && mapa[i+1][j]=='#' && mapa[i][j+1]=='#' && mapa[i][j-1]=='#') costa--;
				}
			}
		}
	}
	printf("%d\n",costa);
	return 0;
}
	

