#include <stdio.h>

int main() {
    double a,b,c,aux;
    int i,j,menor;
    double v[3];
    scanf("%lf %lf %lf",&v[0],&v[1],&v[2]);
    for(i=0;i<2;i++) {
        menor=i;
        for(j=i+1;j<3;j++)
            if(v[menor]<v[j])
                menor=j;
        aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
    a=v[0];
    b=v[1];
    c=v[2];
    if(a>=b+c) {
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    if(a*a==(b*b)+(c*c)) {
        printf("TRIANGULO RETANGULO\n");
    }
    if(a*a>(b*b)+(c*c)) {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if(a*a<(b*b)+(c*c)) {
        printf("TRIANGULO ACUTANGULO\n");
    }
    if(a==b && b==c) {
        printf("TRIANGULO EQUILATERO\n");
    }
    if((a==b && b!=c) || (a==c && a!=b) || (b==c && c!=a)) {
        printf("TRIANGULO ISOSCELES\n");
    } 
    return 0;
}
