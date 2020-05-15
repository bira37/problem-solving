#include <stdio.h>
 
int main() {
    int i,cont=0;
    float num;
    for(i=0;i<6;i++) {
        scanf("%f",&num);
        if(num>0) cont++;
    }
    printf("%d valores positivos\n",cont);
    return 0;
}
