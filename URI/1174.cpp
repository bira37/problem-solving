#include <stdio.h>
#include <stdlib.h>
    
int main() {
    float *vet=(float*)malloc(sizeof(float)*100);
    int i;
    for(i=0;i<100;i++) {
        scanf("%f",&vet[i]);
    }
    for(i=0;i<100;i++) {
        if(vet[i]<=10) {
            printf("A[%d] = %.1f\n",i,vet[i]);
        }
    }
    return 0;
}
