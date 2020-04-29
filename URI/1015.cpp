#include <stdio.h>
#include <math.h>

int main()
{
	float x1,x2,y1,y2,resultado;
	scanf("%f %f\n%f %f",&x1,&y1,&x2,&y2);
	resultado= sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));/* calcula a distancia entre 2 pontos */
	printf("%.4f\n",resultado);
	return 0;
}
