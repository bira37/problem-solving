#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavras{
	int pos;
	char str[51];
};

int compara(const void *a, const void *b){
	int r;
	r=-((strlen(((struct palavras*)a)->str))-(strlen(((struct palavras*)b)->str)));
	if(!r) {
		return (((struct palavras*)a)->pos - ((struct palavras*)b)->pos);
	}
	return (r);
}

int main(void) {
	int n,i,k,j;
	char ch;
	struct palavras cadeia[50];
	scanf("%d",&n);
	for(i=0;i<n;i++){
        k=0;
        while(scanf("%s",cadeia[k++].str),(ch=getchar())!='\n');
		for(j=0;j<k;j++){
        	cadeia[j].pos=j;
        }
        qsort(cadeia,k,sizeof(struct palavras),compara);
        printf("%s",cadeia[0].str);
        for(j=1;j<k;j++) printf(" %s",cadeia[j].str);
        printf("\n");
	}
	return 0;
}
