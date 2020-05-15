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
void insere(Node**t,int n){
	if(!(*t)){
		(*t)=(Node*)malloc(sizeof(Node));
		(*t)->info=n;
		(*t)->esq=NULL;
		(*t)->dir=NULL;
	}
	else {
		if(n <= (*t)->info) insere(&(*t)->esq,n);
		else insere(&(*t)->dir,n);
	}
}
void imprime(Node *t){
	if(t){
		imprime(t->esq);
		printf(" %d",t->info);
		imprime(t->dir);
	}
}
void pre(Node *t){
	if(t){
		printf(" %d",t->info);
		pre(t->esq);
		pre(t->dir);
	}
}
void pos(Node *t){
	if(t){
		pos(t->esq);
		pos(t->dir);
		printf(" %d",t->info);
	}
} 
void libera(Node *t){
	if(t){
		libera(t->esq);
		libera(t->dir);
		free(t);
	}
}

int main(){
	int n,k;
	scanf("%d",&n);
	for(k=1;k<=n;k++){
		Node *raiz;
		raiz=inicializa();
		int size,i,x;
		scanf("%d",&size);
		for(i=0;i<size;i++){
			scanf("%d",&x);
			insere(&raiz,x);
		}
		printf("Case %d:\n",k);
		printf("Pre.:");
		pre(raiz);
		printf("\n");
		printf("In..:");
		imprime(raiz);
		printf("\n");
		printf("Post:");
		pos(raiz);
		printf("\n");
		printf("\n");
		libera(raiz);
	}
	return 0;
}
		
			

	
	
 
	

