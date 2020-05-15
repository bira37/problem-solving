#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *esq;
	struct node *dir;
	char info;
}Node;

Node* inicializa(){
	return NULL;
}

int flag;

void insere(Node**t,char n){
	if(!(*t)){
		(*t)=(Node*)malloc(sizeof(Node));
		(*t)->info=n;
		(*t)->esq=NULL;
		(*t)->dir=NULL;
	}
	else {
		if(n <= (*t)->info) insere(&(*t)->esq,n); //'<=' e '<' da wa, nao muda nada, nao sao inseridos iguais
		else insere(&(*t)->dir,n);
	}
}
void inf(Node *t){
	if(t){
		inf(t->esq);
		if(flag==0){
			 printf("%c",t->info);
			 flag=1;
		}
		else printf(" %c",t->info);
		inf(t->dir);
	}
}
void pre(Node *t){
	if(t){
		if(flag==0){
			 printf("%c",t->info);
			 flag=1;
		}
		else printf(" %c",t->info);
		pre(t->esq);
		pre(t->dir);
	}
}
void pos(Node *t){
	if(t){
		pos(t->esq);
		pos(t->dir);
		if(flag==0){
			 printf("%c",t->info);
			 flag=1;
		}
		else printf(" %c",t->info);
	}
} 
void libera(Node *t){
	if(t){
		libera(t->esq);
		libera(t->dir);
		free(t);
	}
}
int busca(Node *t,char n){
    if(t){
        if(t->info==n) return 1;
        else if(n < t->info) return busca(t->esq,n);
        else return busca(t->dir,n);
    }
    return 0;
}

int main(){
    char op[9];
    char n;
	int b;
    Node *raiz;
    raiz=inicializa();
    while(scanf(" %s",op)!=EOF){
        if(strlen(op)==1){
            if(op[0]=='I'){
                scanf(" %c",&n);
                if(n!=' ' && n!='\n')  insere(&raiz,n);
            }
            else if(op[0]=='P'){
                scanf(" %c",&n);
                b=busca(raiz,n);
                if(b) printf("%c existe\n",n);
                else printf("%c nao existe\n",n);
            }
        }
        else {
			flag=0; //variavel global
            if(op[1]=='N') inf(raiz);
            else if(op[1]=='R') pre(raiz);
            else if(op[1]=='O') pos(raiz);
            printf("\n");
        }
		strcpy(op,"");
    }
    libera(raiz);
    return 0;
}
