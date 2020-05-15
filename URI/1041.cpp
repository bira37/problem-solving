#include <stdio.h>
 
int main() {
    float x,y;
    scanf("%f %f",&x,&y);
    if(x>0) {
        if(y>0)
            printf("Q1\n");
        if(y<0)
            printf("Q4\n");
        if(y==0)
            printf("Eixo X\n");
    }
    if(x<0) {
        if(y>0)
            printf("Q2\n");
        if(y<0)
            printf("Q3\n");
        if(y==0)
            printf("Eixo X\n");
    }
    if(x==0) {
        if(y!=0)
            printf("Eixo Y\n");
        if(y==0)
            printf("Origem\n");
    }
    return 0;
}
