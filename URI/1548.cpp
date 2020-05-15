#include <stdio.h>
void troca(int *x,int *y){
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}
int main() {
    int teste,tamanho,aluno[1000],copia[1000],k,i,j,cont,maior;
    scanf("%d",&teste);
    for(k=0;k<teste;k++){
		cont=0;
        scanf("%d",&tamanho);
        for(i=0;i<tamanho;i++){
            scanf("%d",&aluno[i]);
            copia[i]=aluno[i];
        }
        for(i=0;i<tamanho-1;i++){
            maior=i;
            for(j=i+1;j<tamanho;j++){
                if(aluno[j]>aluno[maior])
                        maior=j;
            }
            troca(&aluno[i],&aluno[maior]);
        }
        for(i=0;i<tamanho;i++){
            if(copia[i]==aluno[i])
                cont++;
        }
        printf("%d\n",cont);
    }
    return 0;
}
