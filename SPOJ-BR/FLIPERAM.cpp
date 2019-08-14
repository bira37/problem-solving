#include <stdio.h>

void merge(int *a,int ini,int meio,int fim){
    int p1=ini,p2=meio+1,i,k,aux[fim-ini+1];
    int tamanho=fim-ini+1;
    for(i=0;i<tamanho;i++){
        if(p1<=meio && p2<=fim){
            if(a[p1]>a[p2]) aux[i]=a[p1++];
            else aux[i]=a[p2++];
        }
        else if(p1>meio) aux[i]=a[p2++];
        else if(p2>fim) aux[i]=a[p1++];
    }
    for(i=ini,k=0;k<tamanho;i++,k++)
        a[i]=aux[k];
}

void divide(int *a,int ini, int fim){
    if(fim<=ini) return;
    int meio=(ini+fim)/2;
    divide(a,ini,meio);
    divide(a,meio+1,fim);
    merge(a,ini,meio,fim);
}


int main(){
	int m,n,i;
	scanf("%d %d",&m,&n);
	int vet[m];
	for(i=0;i<m;i++) scanf("%d",&vet[i]);
	divide(vet,0,m-1);
	for(i=0;i<n;i++) printf("%d\n",vet[i]);
	return 0;
}

