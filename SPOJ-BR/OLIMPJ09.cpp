#include <stdio.h>

struct medal{
	int id;
	int valor;
};

void merge(struct medal *a,int ini,int meio,int fim){
    int p1=ini,p2=meio+1,i,k;
    struct medal aux[fim-ini+1];
    int tamanho=fim-ini+1;
    for(i=0;i<tamanho;i++){
        if(p1<=meio && p2<=fim){
            if(a[p1].valor > a[p2].valor) aux[i]=a[p1++];
	    else if(a[p1].valor < a[p2].valor) aux[i]=a[p2++];
	    else if(a[p1].id < a[p2].id) aux[i]=a[p1++];
	    else aux[i]=a[p2++];
        }
        else if(p1>meio) aux[i]=a[p2++];
        else if(p2>fim) aux[i]=a[p1++];
    }
    for(i=ini,k=0;k<tamanho;i++,k++)
        a[i]=aux[k];
}

void divide(struct medal *a,int ini, int fim){
    if(fim<=ini) return;
    int meio=(ini+fim)/2;
    divide(a,ini,meio);
    divide(a,meio+1,fim);
    merge(a,ini,meio,fim);
}

int main(){
	int n,m,i,j,o,p,b;
	scanf("%d %d",&n,&m);
	struct medal pais[n];
	for(i=0;i<n;i++){
		pais[i].id=i+1;
		pais[i].valor=0;
	}	
	for(i=0;i<m;i++){
		scanf("%d %d %d",&o,&p,&b);
		pais[o-1].valor++;
		pais[p-1].valor++;
		pais[b-1].valor++;
	}
	divide(pais,0,n-1);
	printf("%d",pais[0].id);
	for(i=1;i<n;i++) printf(" %d",pais[i].id);
	printf("\n");
	return 0;
}	

