#include <stdio.h>
#include <string.h>

int main() {
	int tamtia,min=0,max=0,num=0,tam=0,mintia,maxtia,numtia,i;
	char tia[1001];
	scanf("%d %d %d %d",&tamtia,&mintia,&maxtia,&numtia);
	scanf("%s",tia);
	tam=strlen(tia);
	if(tam<tamtia) printf("Ufa :)\n");
	else {
		for(i=0;i<tam;i++){
			if(tia[i]>='a' && tia[i]<='z') min++;
			else if(tia[i]>='A' && tia[i]<='Z') max++;
			else if(tia[i]>='0' && tia[i]<='9') num++;
		}
		if(min>=mintia && (max>=maxtia && num>=numtia)) printf("Ok =/\n");
		else printf("Ufa :)\n");
	}
	return 0;
}
	

