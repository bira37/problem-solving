#include <stdio.h>
#include <string.h>

int main(){
	int i,somapar,somaimpar;
	char num[1001];
	scanf("%s",num);
	//char comp[1]={'0'};
	while(strcmp(num,"0")!=0){
		somapar=0;
		somaimpar=0;
		int tam=strlen(num);
		for(i=0;i<tam;i++){
			if((i+1)%2 == 0){
				somapar=somapar+((int)num[i])-48;
				//printf("soma par= %d\n",somapar);
			}
			else {
			 	somaimpar=somaimpar+((int)num[i])-48;
				//printf("soma impar= %d\n", somaimpar);
			}
		}
		if((abs(somapar-somaimpar))%11 == 0) printf("%s is a multiple of 11.\n",num);
		else printf("%s is not a multiple of 11.\n",num);
		scanf("%s",num);
	}
	return 0;
}


