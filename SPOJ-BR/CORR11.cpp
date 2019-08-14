#include <stdio.h>

struct carros{
	int tempo;
	int id;
};

void merge(struct carros *a,int ini,int meio,int fim){
    int p1=ini,p2=meio+1,i,k;
    struct carros aux[fim-ini+1];
    int tamanho=fim-ini+1;
    for(i=0;i<tamanho;i++){
        if(p1<=meio && p2<=fim){
            if(a[p1].tempo < a[p2].tempo) aux[i]=a[p1++];
            else aux[i]=a[p2++];
        }
        else if(p1>meio) aux[i]=a[p2++];
        else if(p2>fim) aux[i]=a[p1++];
    }
    for(i=ini,k=0;k<tamanho;i++,k++)
        a[i]=aux[k];
}

void divide(struct carros *a,int ini, int fim){
    if(fim<=ini) return;
    int meio=(ini+fim)/2;
    divide(a,ini,meio);
    divide(a,meio+1,fim);
    merge(a,ini,meio,fim);
}

int main() {
	int n,v,i,j,x;
	scanf("%d %d",&n,&v);
	struct carros comp[n];
	for(i=0;i<n;i++){
		comp[i].id=i+1;
		comp[i].tempo=0;
		for(j=0;j<v;j++){
			scanf("%d",&x);
			comp[i].tempo+=x;
		}
	}
	divide(comp,0,n-1);
	printf("%d\n%d\n%d\n",comp[0].id,comp[1].id,comp[2].id);
	return 0;
}

