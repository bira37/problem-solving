#include <stdio.h>
#include <string.h>

int main(){
	int n,flag,i,j;
	char palavra[43];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		flag=0;
		scanf("%s",palavra);
		char resp[43];
		strcpy(resp,palavra);
		int tam=strlen(palavra);
		for(j=0;j<tam;j++){
			if(palavra[j]>='A' && palavra[j]<='Z'){
				palavra[j]=palavra[j]+32;
			}
		}
		j=0;
		while(j<tam-1 && flag==0) {
			if(palavra[j]>=palavra[j+1])
				flag=1;
			j++;
		}
		if(flag==1) printf("%s: N\n",resp);
		else printf("%s: O\n",resp);
	}
	return 0;
}

