#include <stdio.h>

int main()
{
    int limiteMIN, limiteMAX, i,j,k;
    int soma=0;
    scanf("%d\n%d",&limiteMIN,&limiteMAX);
    if(limiteMIN>=limiteMAX){ 
        i=limiteMAX;
        j=limiteMIN;
    }
    else {
        i=limiteMIN;
        j=limiteMAX;
    }
    for(k=i+1; k<j;k++){
        if(k%2 !=0){ 
			soma=soma+k;
		}
    }
    printf("%d\n",soma);
    return 0;
}
