#include <stdio.h>
 
int main() {
    int tempo,h=0,m=0;
    scanf("%d",&tempo);
    while(tempo>=3600){
        tempo-=3600;
        h++;
    }
    while(tempo>=60){
        tempo-=60;
        m++;
    }
    printf("%d:%d:%d\n",h,m,tempo);
    return 0;
}
