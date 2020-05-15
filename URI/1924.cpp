#include <stdio.h>
 
int main() {
    char str[101];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%50[^\n]",str);
    }
    printf("Ciencia da Computacao\n");
    return 0;
}
