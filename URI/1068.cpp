#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

typedef struct _pilha{
    int n;
    char formador[N];
}Pilha;

Pilha* cria_pilha(){
    Pilha *f=(Pilha*)malloc(sizeof(Pilha));
    f->n=0;
    return f;
}

void insere_pilha(Pilha* f,char p){
        f->formador[f->n] = p;
        f->n++;
}

char remove_pilha(Pilha *f){
    char r=f->formador[f->n-1];
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
	if(f->n < N) return 1;
	else return 0;
}

void free_pilha(Pilha* f){
	free(f);
}
 
int main() {
    int i,num,flag,tamanho,count;
    char ch[1000];
    while(scanf("%s",ch)!=EOF){
        flag=0;
        count=0;
	    Pilha* mat = cria_pilha();
        tamanho=strlen(ch);
        for(i=0;i<tamanho;i++){
            if(ch[i]=='('){
              	if(checa_full(mat)) insere_pilha(mat,ch[i]);
            }
            else if(ch[i]==')'){
                count++;
                if(checa_vazia(mat)){
                    remove_pilha(mat);
					count--;
                }
                else {
                    flag=1;
                    break;
                }
            }
        }
		if(mat->n != 0 || count !=0) flag=1;
    	if(flag==0) printf("correct\n");
    	else printf("incorrect\n");
		free_pilha(mat);
    }
    return 0;
}
