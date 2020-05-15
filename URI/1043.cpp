#include <stdio.h>
 
int main() {
    float c,b,a,resultado;
    scanf("%f %f %f",&a,&b,&c);
    if((a<b+c && b<a+c) && c<a+b) { //verifica se forma triangulo
        resultado=a+b+c;
        printf("Perimetro = ");
    }
    else {
        resultado= (a+b)*c/2;
        printf("Area = ");
    }
    printf("%.1f\n",resultado);
    return 0;
}
