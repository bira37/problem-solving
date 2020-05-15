#include <stdio.h>
 
int main() {
    float n1,n2,n3,n4,media=0,exame=0,media2=0;
    scanf("%f %f %f %f",&n1,&n2,&n3,&n4);
    media=((n1*2)+(n2*3)+(n3*4)+(n4*1))/10.0;
	printf("Media: %.1f\n",media);
    if(media>=5.0 && media<7.0){
        printf("Aluno em exame.\n");
        scanf("\n%f",&exame);
		printf("Nota do exame: %.1f\n",exame);
        media2=(exame+media)/2.0;
        if(media>=5.0){
            printf("Aluno aprovado.\nMedia final: %.1f\n",media2);
        }
        else printf("Aluno reprovado.\n");
	}
    if(media<5.0)
        printf("Aluno reprovado.\n");
    if(media>=7.0)
        printf("Aluno aprovado.\n");
    return 0;
}
