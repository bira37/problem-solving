#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pilha{
    int n;
    char vagoes[30];
}Pilha;

Pilha* cria_pilha(){
    Pilha *f=(Pilha*)malloc(sizeof(Pilha));
    f->n=0;
    return f;
}

void insere_pilha(Pilha* f,char p){
        f->vagoes[f->n] = p;
        f->n++;
}

char remove_pilha(Pilha *f){
    char r=f->vagoes[f->n-1];
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

void atualiza_pilha(Pilha* f,char *a, char *b, int num){
    int j=0,i=0,k;
	char flag;
    while(j<num){
        if(i<num){
            if(checa_full(f)){
			 	insere_pilha(f,a[i]);
			 	flag='I';
				printf("%c",flag);
			}
            i++;
        }
		if(f->vagoes[(f->n)-1]==b[j]){
        	while(f->vagoes[(f->n)-1]==b[j]){
            	if(checa_vazia(f)){
				 	remove_pilha(f);
					flag='R';
					printf("%c",flag);
				}
				j++;
       	 	}
		}
        else if(f->vagoes[(f->n)-1]!=b[j]){
            if(i==num){
               flag='X';
            } 
        }
		if(flag=='X'){
			 printf(" Impossible");
			 return;
		}
		//printf("pilha: ");
		//for(k=0;k<=f->n-1;k++) printf("%c ",f->vagoes[k]);
		//printf("\n");
    }
    return 1;
}

int main(){
    int i,num;
	char flag,k;
loop:
    while(scanf("%d",&num), num!=0){
		Pilha *trem= cria_pilha();
        flag=1;
        char original[num];
        char bloco[num];
		i=0;
        for(i=0;i<num;i++) scanf(" %c",&original[i]);
		for(i=0;i<num;i++) scanf(" %c",&bloco[i]);
		//for(i=0;i<num;i++) printf("a: %c, b: %c\n",original[i],bloco[i]);
        atualiza_pilha(trem,original,bloco,num);
		printf("\n");	
		free_pilha(trem);
    }
    return 0;
}
