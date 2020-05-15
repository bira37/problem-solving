#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct caracteres{
	char cadeia[201];
};

int compara(const void *x,const void *y){
	return strcmp(((struct caracteres*)x)->cadeia,((struct caracteres*)y)->cadeia);
}

int main() {
    int i,j,k,flag,contador,num,tamanho;
    while(scanf("%d",&num)!=EOF){
		struct caracteres linhas[num];
        contador=0;
        for(i=0;i<num;i++){
			scanf("%s",linhas[i].cadeia);
		}
        tamanho=strlen(linhas[1].cadeia);
		//printf("Antes do qsort\n");
		//for(i=0;i<num;i++) printf("%s\n",linhas[i].cadeia);
        qsort(linhas,num,sizeof(struct caracteres),compara);
		//printf("Depois do qsort\n");
		//for(i=0;i<num;i++) printf("%s\n",linhas[i].cadeia);
        i=0;
		k=1;
    	while(k<num){
			j=0;
			flag=0;
			if(linhas[i].cadeia[0]!=linhas[k].cadeia[0]) i=k;
			else {
					while(linhas[i].cadeia[j]==linhas[k].cadeia[j] && (j<tamanho && flag==0)){
						contador++;
               	    	j++;
						if(j<tamanho && linhas[i].cadeia[j]!=linhas[k].cadeia[j]){
							i=k;
							flag=1;
						}			
					}
			}
			k++;
		}
        printf("%d\n",contador);
	}
    return 0;
}
