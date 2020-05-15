#include <stdio.h>
  
int calculaTempo(int totalA,int totalB,float taxaA,float taxaB, int j,int tempo) {
    while(totalA<=totalB) {
        totalA+=(totalA*(taxaA/100));
        totalB+=(totalB*(taxaB/100));
        tempo+=1;
        if(tempo>100)
            break;
    }
    if(tempo<=100)
        printf("%d anos.\n",tempo);
    else printf("Mais de 1 seculo.\n");
    return 0;
} 
  
int main() {
    int popA,popB,i,j,totalA,totalB,testes,tempo;
    float taxaA,taxaB;
    scanf("%d",&testes);
    for(i=1;i<=testes;i++) {
        scanf("%d %d %f %f",&popA,&popB,&taxaA,&taxaB);
        totalA=popA;
        totalB=popB;
        tempo=0;
        calculaTempo(totalA,totalB,taxaA,taxaB,j,tempo);
    }
    return 0;
}
