#include <stdio.h>
 
int main() {
    int numeroA, numeroB;
    scanf("%d %d",&numeroA,&numeroB);
    if(numeroA>=numeroB) {
        if(numeroA%numeroB==0)
            printf("Sao Multiplos\n");
        else
            printf("Nao sao Multiplos\n");
    }
    else {
        if(numeroB%numeroA==0)
            printf("Sao Multiplos\n");
        else
            printf("Nao sao Multiplos\n");
    }
    return 0;
}
