#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *prox;
}Lista;

void insere(Lista **l,int n){
    if(!(*l)){
        *l=(Lista*)malloc(sizeof(Lista));
        (*l)->info = n;
        (*l)->prox=*l;
    }
    else {
        Lista *novo=(Lista*)malloc(sizeof(Lista));
        novo->info = n;
        novo->prox=(*l)->prox;
        (*l)->prox = novo;
        *l = novo;
    }
} 

void imprime(Lista *l){
    Lista *p=l;
    if(p){
		p=p->prox;
        do{
			printf("%d -> ",p->info);
			p=p->prox;
		}while(p!=l->prox);
    }
    printf("\\\n");
}
int main() {
    int testes,i,k,ch,end,x,flag=0;
    scanf("%d",&testes);
    for(k=0;k<testes;k++){
        if(flag==0) flag=1;
        else printf("\n");
        scanf("%d %d",&end,&ch);
        Lista *address[end];
		for(i=0;i<end;i++) address[i]=NULL;
        for(i=0;i<ch;i++){
            scanf("%d",&x);
            insere(&address[x%end],x);
        }
        for(i=0;i<end;i++){
			printf("%d -> ",i);
            imprime(address[i]);
        }
    }
    return 0;
}
