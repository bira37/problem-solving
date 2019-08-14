#include <stdio.h>

int main(){
	int n,i;
	scanf("%d",&n);
	int campo[n];
	int contador[n];
	for(i=0;i<n;i++){
		scanf("%d",&campo[i]);
		contador[i]=0;
	}
	if(campo[0]==1) contador[0]++;
	if(campo[1]==1) contador[0]++;
	if(campo[n-1]==1) contador[n-1]++;
	if(campo[n-2]==1) contador[n-1]++;
	for(i=1;i<n-1;i++){
		if(campo[i]==1) contador[i]++;
		if(campo[i-1]==1) contador[i]++;
		if(campo[i+1]==1) contador[i]++;
	}
	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",contador[i]);
	}
	printf("\n");
	return 0;
}	

