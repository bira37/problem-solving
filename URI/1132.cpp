#include <stdio.h>
 
int main() {
    int n,i,m,sum=0;
    scanf("%d %d",&n,&m);
    if(n>m) {
        for(i=m;i<=n;i++) if(i%13!=0) sum+=i;
    }
    else {
        for(i=n;i<=m;i++) if(i%13!=0) sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}
