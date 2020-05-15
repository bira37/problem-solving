#include <stdio.h>
 
int main() {
    int esq,dir;
    while(scanf("%d %d",&esq,&dir), esq+dir!=0) printf("%d\n",esq+dir);
    return 0;
}
