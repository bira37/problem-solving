#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *esq;
	struct node *dir;
	int info;
}Node;

Node* inicializa(){
	return NULL;
}

int flag;

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
void inf(Node *t){
	if(t){
		inf(t->esq);
		if(flag==0){
			 printf("%d",t->info);
			 flag=1;
		}
		else printf(" %d",t->info);
		inf(t->dir);
	}
}
void pre(Node *t){
	if(t){
		if(flag==0){
			 printf("%d",t->info);
			 flag=1;
		}
		else printf(" %d",t->info);
		pre(t->esq);
		pre(t->dir);
	}
}
void pos(Node *t){
	if(t){
		pos(t->esq);
		pos(t->dir);
		if(flag==0){
			 printf("%d",t->info);
			 flag=1;
		}
		else printf(" %d",t->info);
	}
} 
void libera(Node *t){
	if(t){
		libera(t->esq);
		libera(t->dir);
		free(t);
	}
}
Node* busca(Node *t,int n){
    if(t){
        if(t->info==n) return t;
        else if(n < t->info) return busca(t->esq,n);
        else return busca(t->dir,n);
    }
    return NULL;
}

Node* buscaPaiMaior(Node *t){
	if(t->dir == NULL) return t;
	if(t->dir->dir==NULL) return t;
	else return buscaPaiMaior(t->dir);
}

void atualiza(Node **t) {
	Node *rem=*t;
	if(!(*t)->esq){
		(*t)=(*t)->dir;
		free(rem);
	}
	else if(!(*t)->dir) {
	    (*t)=(*t)->esq;
	    free(rem);
	}
	else {
		Node *Paimaior=buscaPaiMaior((*t)->esq);
		if(Paimaior->dir == NULL ){
			(*t)=Paimaior;
			(*t)->dir=rem->dir;
			free(rem);
		}
		else {
			(*t)=Paimaior->dir;
			Paimaior->dir=(*t)->esq;
			(*t)->dir=rem->dir;
			(*t)->esq=rem->esq;
			free(rem);
		}
	}	
}

void pop(Node **t, int n){
	if((*t)){
		if((*t)->info == n) atualiza(t);	
		else if(n < (*t)->info) pop(&(*t)->esq,n);
		else if(n > (*t)->info) pop(&(*t)->dir,n);
	}
}

int main(){
    char op[9];
    int n;
	Node *b;
    Node *raiz;
    raiz=inicializa();
    while(scanf(" %s",op)!=EOF){
        if(strlen(op)==1){
            if(op[0]=='I'){
                scanf(" %d",&n);
                insere(&raiz,n);
            }
            else if(op[0]=='P'){
                scanf(" %d",&n);
                b=busca(raiz,n);
                if(b) printf("%d existe\n",n);
                else printf("%d nao existe\n",n);
            }
            else if(op[0]=='R'){
                scanf(" %d",&n);
                pop(&raiz,n);
            }
        }
        else {
			flag=0; //variavel global
            if(op[1]=='N') inf(raiz);
            else if(op[1]=='R') pre(raiz);
            else if(op[1]=='O') pos(raiz);
            printf("\n");
        }
    }
    libera(raiz);
    return 0;
}
