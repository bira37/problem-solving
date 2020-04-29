#include <stdio.h>

int calculaIntervalo(double num){
    if(num<0 || num>100)
        printf("Fora de intervalo\n");
    else {
        if(num<=25)
            printf("Intervalo [0,25]\n");
        else if(num<=50)
            printf("Intervalo (25,50]\n");
        else if(num<=75)
            printf("Intervalo (50,75]\n");
        else if(num<=100)
            printf("Intervalo (75,100]\n");
    }
    return 0;
}
int main() {
    double num;
    scanf("%lf",&num);
    calculaIntervalo(num);
    return 0;
}
