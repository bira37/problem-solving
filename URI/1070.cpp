#include <stdio.h>
 
int main() {
    int x,i,j;
    scanf("%d",&x);
    if(x%2==0) i=x+1;
    else x=i;
    for(j=0;j<6;j++) {
        printf("%d\n",i);
        i+=2;
    }
    return 0;
}
