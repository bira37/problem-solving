#include <stdio.h>

int main(){
	int n,i,entrada,notas[200],frequencia=0,maior=0;
	for(i=0;i<201;i++){
		notas[i]=0;	
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&entrada);
		notas[entrada]++;
	}
	for(i=1;i<201;i++){
		if((frequencia<notas[i]) || (frequencia == notas[i] && i>maior)){
		maior=i;
		frequencia=notas[i];
		}
	}
	printf("%d\n",maior);
	return 0;
}
		
		


