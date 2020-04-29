#include <stdio.h>
#include <math.h> 
//calculo de raizes de equaçao do segundo grau
int calculaRaiz(double a, double b, double c, double raiz1, 
    double raiz2,double delta, double raizDelta) {
    delta=(b*b)-(4*a*c);
    if(a==0 || delta<0)
        printf("Impossivel calcular\n");
    else {
        raizDelta=sqrt(delta);
        raiz1=(-b+raizDelta)/(a*2);
        raiz2=(-b-raizDelta)/(a*2);
        printf("R1 = %.5lf\nR2 = %.5lf\n",raiz1,raiz2);
    }
    return 0;
}
int main() {
    double a,b,c,raiz1,raiz2,delta,raizDelta;
    scanf("%lf %lf %lf",&a,&b,&c);
    calculaRaiz(a,b,c,raiz1,raiz2,delta,raizDelta);
    return 0;
}
