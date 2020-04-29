#include <stdio.h>
 
int main() {
    int tempo,a=0,m=0;
    scanf("%d",&tempo);
    while(tempo>=365){
        tempo-=365;
        a++;
    }
    while(tempo>=30){
        tempo-=30;
        m++;
    }
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",a,m,tempo);
    return 0;
}
