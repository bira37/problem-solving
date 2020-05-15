#include <stdio.h>
#include <stdlib.h>

char prefixo[53];
char infixo[53];

void formapos(int inip,int fimp,int inii,int fimi){
    int p1=inip,p2=fimp,i1=inii,i2=fimi;
    if(i2<i1 || p2<p1) return;
    while(prefixo[p1]!=infixo[i1] && i1<=i2) i1++;
	char r=prefixo[inip];
	int i;
	for(i=p1;i<i1;i++) prefixo[i]=prefixo[i+1];
    formapos(p1,i1,p1,i1-1);
    formapos(i1+1,i2,i1+1,i2);
	printf("%c",r);
}
 
int main() {
    int casos,k;
    scanf("%d",&casos);
    for(k=0;k<casos;k++){
        int t;
        scanf("%d",&t);
        scanf("%s",prefixo);
		scanf("%s",infixo);
        formapos(0,t-1,0,t-1);
        printf("\n");
    }
    return 0;
}
