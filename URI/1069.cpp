#include <stdio.h>
#include <stdlib.h>
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
    int i,num,count;
    char ch;
    scanf("%d\n",&num);
    for(i=0;i<num;i++){
	Pilha* mina = cria_pilha();
        count=0;
        while(ch=getchar(),ch!='\n'){
            if(ch=='<'){
              	if(checa_full(mina)) insere_pilha(mina,ch);
            }
            else if(ch=='>'){
                if(checa_vazia(mina)){
                    remove_pilha(mina);
                    count++;
                }
            } 
        }
        printf("%d\n",count);
	free_pilha(mina);
    }
    return 0;
}

