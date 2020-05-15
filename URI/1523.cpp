#include <stdio.h>
#include <stdlib.h>

typedef struct _carros{
    int chegada,saida;
}Carros;

typedef struct _pilha{
    int n;
    Carros horarios[1000];
}Pilha;

Pilha* cria_pilha(){
    Pilha *f=(Pilha*)malloc(sizeof(Pilha));
    f->n=0;
    return f;
}

void insere_pilha(Pilha* f,int in,int out){
        f->horarios[f->n].chegada = in;
        f->horarios[f->n].saida = out;
        f->n++;
}

Carros remove_pilha(Pilha *f){
    Carros r=f->horarios[f->n-1];
    f->n--;
    return r;

}

int checa_vazia(Pilha* f){
    if(f->n > 0){
        return 1;
    }
    else return 0;
}

int checa_full(Pilha *f, int N){
	if(f->n < N) return 1;
	else return 0;
}

void free_pilha(Pilha* f){
	free(f);
}

int atualiza_pilha(Pilha* f, int in, int out,int vagas){
    int i, flag=0;
    for(i=f->n-1;i>=0;i--){
        if(f->horarios[i].saida <= in && checa_vazia(f) ) remove_pilha(f);
        else break;
    }
    if(!checa_vazia(f)){
        insere_pilha(f, in, out);
		return 1;
    }
    for(;i>=0;i--){
        if(f->horarios[i].saida < out ) return 0;
    }
	if(checa_full(f,vagas)){
		 insere_pilha(f, in, out);
		 return 1;
	}
	else return 0;
}

int main(){
    int vagas,ncarros,i,in,out,flag;
    while(scanf("%d %d",&ncarros,&vagas), vagas+ncarros!=0){
        Pilha *estacionamento= cria_pilha();
        flag=1;
        for(i=0;i<ncarros;i++){
            scanf("%d %d",&in,&out);
            if(flag==1) flag=atualiza_pilha(estacionamento,in,out,vagas);
        }
        if(flag==1) printf("Sim\n");
        else if(flag==0) printf("Nao\n");
        free_pilha(estacionamento);
    }
}
