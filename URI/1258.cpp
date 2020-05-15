#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _roupas{
	char nome[50];
	char cor[20];
	char tamanho;
}roupa;

int main(void) {
	int num,i,j,flag=0,menor;
	roupa aux;
	scanf("%d",&num);
	while(num!=0){
		roupa aluno[num];
		for(i=0;i<num;i++){
			gets(aluno[i].nome);
            if(strlen(aluno[i].nome)==0){
                i--;
                continue;
            }
            scanf("%s %c",aluno[i].cor,&aluno[i].tamanho);
		}
		for(i=0;i<num;i++){
            menor=i;
            for(j=i+1;j<num;j++){
                if(strcmp(aluno[j].cor,aluno[menor].cor)<0) menor=j;
                else if(strcmp(aluno[j].cor,aluno[menor].cor)==0 && (int)aluno[j].tamanho>(int)aluno[menor].tamanho) menor=j;
                else if((strcmp(aluno[j].cor,aluno[menor].cor)==0 && (int)aluno[j].tamanho==(int)aluno[menor].tamanho)&& strcmp(aluno[j].nome,aluno[menor].nome)<0) menor=j;
            }
            aux=aluno[i];
            aluno[i]=aluno[menor];
            aluno[menor]=aux;
		}
		if(flag==1) printf("\n");
		for(i=0;i<num;i++){
            printf("%s %c %s\n",aluno[i].cor,aluno[i].tamanho,aluno[i].nome);
		}
		if(flag==0) flag=1;
		scanf("%d",&num);
	}
	return 0;
}

