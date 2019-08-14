#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tetris{
	char nome[20];
	int pontos;
}Jogo;

void divide(Jogo *a,int ini, int fim){
	if(fim<=ini) return;
	int meio=(ini+fim)/2;
	divide(a,ini,meio);
	divide(a,meio+1,fim);
	ordena(a,ini,meio,fim);
}

void ordena(Jogo *a,int ini,int meio, int fim){
	int k,p1=ini,p2=meio+1,tamanho=fim-ini+1;
	Jogo aux[tamanho];
	int i;
	for(i=0;i<tamanho;i++){
		if(p1<=meio && p2<=fim){
				if(a[p1].pontos>a[p2].pontos) aux[i]=a[p1++];
				else if(a[p2].pontos>a[p1].pontos) aux[i]=a[p2++];
				else if(strcmp(a[p1].nome,a[p2].nome)<0) aux[i]=a[p1++];
				else aux[i]=a[p2++];
		}
		else if(p1>meio) aux[i]=a[p2++];
		else if(p2>fim) aux[i]=a[p1++];
	}
	for(i=ini,k=0;k<tamanho;i++,k++)
		a[i]=aux[k];
}

int main(void) {
	int n,teste=0;
	while(scanf("%d",&n),n!=0){
		int maior,menor,valor,contador=1;
		Jogo alunos[n];
		int i;
		int j;
		for(i=0;i<n;i++){
			alunos[i].pontos=0;
			menor=1001;maior=-1;
			scanf("%s",alunos[i].nome);
			for(j=0;j<12;j++){
				scanf("%d",&valor);
				if(valor<menor) menor=valor;
				if(valor>maior) maior=valor;
				alunos[i].pontos+=valor;
			}
			alunos[i].pontos=alunos[i].pontos-(maior+menor);
		}
		divide(alunos,0,n-1);
		teste++;
		printf("Teste %d\n",teste);
		printf("%d %d %s\n",contador,alunos[0].pontos,alunos[0].nome);
		for(i=1;i<n;i++){
			if(alunos[i].pontos!=alunos[i-1].pontos) contador=i+1;
			printf("%d %d %s\n",contador,alunos[i].pontos,alunos[i].nome);
		}
		printf("\n");
	}
	return 0;
}
