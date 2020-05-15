#include <stdio.h>
 
int main() {
    int i,j,k,chegada[30],largada[30],n,contador,carro,aux;
    while(scanf("%d",&n)!=EOF){
        contador=0;
        for(i=0;i<n;i++){
           scanf("%d",&largada[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&chegada[i]);
        }
        for(i=n-1;i>=0;i--){
            for(j=0;j<n;j++){
                if(largada[j]==chegada[i]){
                    aux=largada[j];
                    for(k=j;k<i;k++){
                        largada[k]=largada[k+1];
                    }
                    largada[i]=aux;
			    	contador=contador+abs(j-i);
                }
            }
        }
	printf("%d\n",contador);
    }
    return 0;
}
