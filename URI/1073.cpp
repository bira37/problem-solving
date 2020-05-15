#include <stdio.h>
 
int main() {
    long long x,i=2;
    scanf("%lld",&x);
    while(i<=x){
        printf("%lld^2 = %lld\n",i,i*i);
        i+=2;
    }
    return 0;
}
