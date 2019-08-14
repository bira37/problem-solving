#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alunos{
	char nome[25];
	int nota;
};

int compara(const void *a, const void *b){
	if(((struct Alunos*)a)->nota == ((struct Alunos*)b)->nota)
		return -strcmp(((struct Alunos*)a)->nome,((struct Alunos
*)b)->nome);
	return ((struct Alunos*)a)->nota - ((struct Alunos*)b)->nota;
}

int main() {
	int n,i,teste=0;
	while(scanf("%d",&n)!=EOF){
		struct Alunos turma[n];
		for(i=0;i<n;i++){
			scanf(" %s %d",turma[i].nome,&turma[i].nota);
		}
		qsort(turma,n,sizeof(struct Alunos),compara);
		teste++;
		printf("Instancia %d\n",teste);
		printf("%s\n\n",turma[0].nome);
	}
	return 0;
}

