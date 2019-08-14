#include <stdio.h>
int main(){
	int i,j,n,mov,posx=4,posy=3,count=0,resp=1;
	int tab[8][8];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			tab[i][j]=0;
		}
	}
	tab[1][3]=1;
	tab[2][3]=1;
	tab[2][5]=1;
	tab[5][4]=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&mov);
		if(resp==1){
			if(mov==1){
				posx+=1;
				posy+=2;
			}
			else if(mov==2){
				posx+=2;
				posy+=1;
			}
			else if(mov==3){
				posx+=2;
				posy-=1;
			}
			else if(mov==4){
				posx+=1;
				posy-=2;
			}
			else if(mov==5){
				posx-=1;
				posy-=2;
			}
			else if(mov==6){
				posx-=2;
				posy-=1;
			}
			else if(mov==7){
				posx-=2;
				posy+=1;
			}
			else if(mov==8){
				posx-=1;
				posy+=2;
			}
			count++;
			if(tab[posx][posy]==1) resp=0;
		}
	}
	printf("%d\n",count);
	return 0;
}

