#include <stdio.h>
 
int main() {
    int n,x,in=0,out=0;
    scanf("%d",&n);
    while(n-- > 0) {
        scanf("%d",&x);
        if(x<=20 && x>=10) in++;
        else out++;
    }
    printf("%d in\n%d out\n",in,out);
    return 0;
}
