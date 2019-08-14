#include <stdio.h>

int main(){
	int i,j,n;
	scanf("%d",&n);
	int a[n][n],somador;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&somador);
			a[i][j]=a[i][j]+somador;
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i][0]);
		for(j=1;j<n;j++)
			printf(" %d",a[i][j]);
		printf("\n");
	}
	return 0;
}
			

