#include <stdio.h>

void merge(int *a,int ini,int meio,int fim){
    int p1=ini,p2=meio+1,i,k;
    int aux[fim-ini+1];
    int tamanho=fim-ini+1;
    for(i=0;i<tamanho;i++){
        if(p1<=meio && p2<=fim){
            if(a[p1] < a[p2]) aux[i]=a[p1++];
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

int main() {
    int caso=1,n,p,x,i;
	int pos[10001];
    while(scanf("%d %d",&n,&p),p+n!=0) {
        int marmores[n];
		for(i=0;i<10001;i++)
			pos[i]=0;
        for(i=0;i<n;i++)
            scanf("%d",&marmores[i]);
        divide(marmores,0,n-1);
		for(i=0;i<n;i++){
			if(pos[marmores[i]]==0)
				pos[marmores[i]]=i+1;
		}
        printf("CASE# %d:\n",caso++);
        for(i=0;i<p;i++) {
            scanf("%d",&x);
            if(pos[x]!=0) printf("%d found at %d\n",x,pos[x]);
            else if(pos[x]==0) printf("%d not found\n",x);
        }
    }
    return 0;
}
