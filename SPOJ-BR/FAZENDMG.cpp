#include <stdio.h>
int m[1501][1501];
int main(){
	int i,j,x,y,n,l,c,km,cerca,k;
	while(scanf("%d",&n),n!=0){
		km=0;
		cerca=0;
		for(i=0;i<1500;i++)
			for(j=0;j<1500;j++)
				m[i][j]=0;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d",&x,&y,&l,&c);
			for(j=x;j<x+l;j++){
				for(k=y;k<y+c;k++){
					if(m[j][k]==0){
						m[j][k]=1;
						km++;
					}
				}
			}
		}
		for(i=0;i<1500;i++){
			for(j=0;j<1500;j++){
				if(m[i][j]==1){
					if(i==0 || i==1499) cerca++;
					if(j==0 || j==1499) cerca++;
					if(i<1499 && m[i+1][j]==0) cerca++;
					if(i>0 && m[i-1][j]==0) cerca++;
					if(j>0 && m[i][j-1]==0) cerca++;
					if(j<1499 && m[i][j+1]==0) cerca++;
				}
			}
		}			 	
		printf("%d %d\n",km,cerca);
	}
	return 0;
}
	

