#include <stdio.h>
 
int main() {
    int numero,i,fat=1;
    scanf("%d",&numero);
    if(numero==1)
        printf("1\n");
    else {
        for(i=2;i<=numero;i++) {
            fat*=i;
        }
        printf("%d\n",fat);
    }
    return 0;
}
