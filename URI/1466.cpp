#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *esq;
	struct node *dir;
	int info;
}Node;

Node* inicializa(){
	return NULL;
}

int j;

struct pos{
	int valor;
	int lugar;
};

struct pos nivel[501];

void insere(Node**t,int n){
	if(!(*t)){
		(*t)=(Node*)malloc(sizeof(Node));
		(*t)->info=n;
		(*t)->esq=NULL;
		(*t)->dir=NULL;
	}
	else {
		if(n < (*t)->info) insere(&(*t)->esq,n);
		else insere(&(*t)->dir,n);
	}
}

void libera(Node *t){
	if(t){
		libera(t->esq);
		libera(t->dir);
		free(t);
	}
}

void montanivel(Node *t, int p){
    if(t){
        nivel[j].valor=t->info;
		nivel[j++].lugar=p;
        montanivel(t->esq,2*p);
        montanivel(t->dir,(2*p)+1);
    }
}

int cmp(const void*a,const void*b){
    return (((struct pos*)a)->lugar - ((struct pos*)b)->lugar);
}

int main(){
    int k,n;
    scanf("%d",&n);
    for(k=1;k<=n;k++){
		j=0;
        Node* raiz;
        int i;
        raiz=inicializa();
        int size,x;
        scanf("%d",&size);
		int max=size*4;
        for(i=0;i<size;i++){
            scanf("%d",&x);
            insere(&raiz,x);
        }
        montanivel(raiz,1);
        qsort(nivel,j,sizeof(struct pos),cmp);
        printf("Case %d:\n",k);
        printf("%d",nivel[0].valor);
        for(i=1;i<size;i++){
            printf(" %d",nivel[i].valor);
        }
		printf("\n\n");
        libera(raiz);
    }
}
