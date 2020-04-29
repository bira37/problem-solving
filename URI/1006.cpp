#include <stdio.h>

int main() {
    double a,b,c,resultado;
    scanf("%lf\n%lf\n%lf",&a,&b,&c);
	resultado= ((a*2.0)+(b*3.0)+(c*5.0))/10;
    printf("MEDIA = %.1lf\n",resultado);
    return 0;
}
