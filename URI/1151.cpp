#include <stdio.h>
 
int main() {
    int num,anterior1,anterior2,i,proximo;
    scanf("%d",&num);
    if(num==1)
        printf("0\n");
    else if(num==2)
        printf("0 1\n");
    else if(num>=3) {
        printf("0 1");
        anterior1=0;
        anterior2=1;
        for(i=3;i<=num;i++) {
            proximo=anterior1+anterior2;
            printf(" %d",proximo);
            anterior1=anterior2;
            anterior2=proximo;
        }
        printf("\n");
    }
    return 0;
}
