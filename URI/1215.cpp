#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *esq;
	struct node *dir;
	char info[201];
}Node;

Node* inicializa(){
	return NULL;
}

int flag;

void insere(Node**t,char* n){
	if(!(*t)){
		(*t)=(Node*)malloc(sizeof(Node));
		strcpy((*t)->info,n);
		(*t)->esq=NULL;
		(*t)->dir=NULL;
	}
	else {
		if(strcmp(n,(*t)->info) < 0) insere(&(*t)->esq,n); //'<=' e '<' da wa, nao muda nada, nao sao inseridos iguais
		else if(strcmp(n,(*t)->info) > 0) insere(&(*t)->dir,n);
	}
}
void inf(Node *t){
	if(t){
		inf(t->esq);
		printf("%s\n",t->info);
		inf(t->dir);
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
    Node* raiz;
    raiz=inicializa();
    char str[201];
    char c;
	int size,i,k=0;
   	while(scanf("%c",&c)!=EOF){
		if((c>='A' && c<='Z') || (c>='a' && c<='z')){
			//printf("%c\n",c);
			if('A'<=c && c<='Z') c+='a'-'A';
			str[k++]=c;
			//printf("%c\n",str[k-1]);
		}
		else {
			str[k]='\0';
        	if(strcmp(str," ")!=0 && strlen(str)>0) insere(&raiz,str);
			k=0;
			char str[201];
		}
    }
	str[k]='\0';
    if(strcmp(str," ")!=0 && strlen(str)>0) insere(&raiz,str);
    inf(raiz);
    libera(raiz);
}
