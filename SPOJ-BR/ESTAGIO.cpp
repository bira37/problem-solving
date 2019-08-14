#include <stdio.h>

struct sala{
	int id;
	int nota;
};

int main(){
	int n,teste=0,i,maiornota,flag;
	scanf("%d",&n);
	while(n!=0){
		maiornota=0;
		flag=0;
		struct sala alunos[n];
		for(i=0;i<n;i++){
			scanf("%d %d",&alunos[i].id,&alunos[i].nota);
			if(alunos[i].nota>maiornota) maiornota=alunos[i].nota;
		}
		teste++;
		printf("Turma %d\n",teste);
		for(i=0;i<n;i++){
			if(alunos[i].nota==maiornota && flag==0){
				printf("%d",alunos[i].id);
				flag=1;
			}
			else if(alunos[i].nota==maiornota && flag==1){
				printf(" %d",alunos[i].id);
			}
		}
		printf("\n\n");
		scanf("%d",&n);
	}
	return 0;
}
			
		

