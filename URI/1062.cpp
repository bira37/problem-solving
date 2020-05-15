#include <stdio.h>
#include <stdlib.h>

typedef struct _pilha{
    int n;
    int vagoes[1000];
}Pilha;

Pilha* cria_pilha(){
    Pilha *f=(Pilha*)malloc(sizeof(Pilha));
    f->n=0;
    return f;
}

void insere_pilha(Pilha* f,int p){
        f->vagoes[f->n] = p;
        f->n++;
}

int remove_pilha(Pilha *f){
    int r=f->vagoes[f->n-1];
    f->n--;
    return r;
    
}

int checa_vazia(Pilha* f){
    if(f->n > 0){
        return 1;
    }
    else return 0;
}

int checa_full(Pilha *f){
	if(f->n < 1000) return 1;
	else return 0;
}

void free_pilha(Pilha* f){
	free(f);
}

int atualiza_pilha(Pilha* f,int *a, int *b, int num){
    int j=0,i=0,flag=1,k;
    while(j<num){
        if(i<num){
            if(checa_full(f)) insere_pilha(f,a[i]);
            i++;
        }
		if(f->vagoes[(f->n)-1]==b[j]){
        	while(f->vagoes[(f->n)-1]==b[j]){
            	if(checa_vazia(f)) remove_pilha(f);
				j++;
       	 	}
		}
        else if(f->vagoes[(f->n)-1]!=b[j]){
            if(i==num){
               return 0;
            } 
        }
		//printf("pilha: ");
		//for(k=0;k<=f->n-1;k++) printf("%d ",f->vagoes[k]);
		//printf("\n");
    }
    return 1;
}

int main(){
    int i,flag,num;
loop:
    while(scanf("%d",&num), num!=0){
		Pilha *trem= cria_pilha();
        flag=1;
        int original[num];
        int bloco[num];
        for(i=0;i<num;i++) original[i]=i+1;
		scanf("%d",&bloco[0]);
        while(bloco[0]!=0){
			for(i=1;i<num;i++) scanf("%d",&bloco[i]);
			//for(i=0;i<num;i++) printf("a: %d, b: %d\n",original[i],bloco[i]);
        	flag = atualiza_pilha(trem,original,bloco,num);
        	if(flag==1) printf("Yes\n");
        	else if(flag==0) printf("No\n");
			scanf("%d",&bloco[0]);
		}	
		if(bloco[0]==0) printf("\n");
		free_pilha(trem);
    }
    return 0;
}
