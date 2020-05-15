#include <stdio.h>
#include <string.h>

struct Caractere{
    int asc;
    int contador;
}; 

int main() {
    struct Caractere aux;
    int i,j,k,menor,tamanho,flag=0;
    char texto[1001];
    while(scanf("%s",texto)!=EOF){
        tamanho=strlen(texto);
        struct Caractere letras[129];
        for(i=0;i<129;i++){
            letras[i].contador=0;
            letras[i].asc=i;
        }
        for(i=0;i<tamanho;i++){
            letras[(int)texto[i]].contador++;
        }
        for(i=0;i<129;i++){
            menor=i;
            for(j=i+1;j<129;j++){
                if(letras[j].contador<letras[menor].contador) menor=j;
                if(letras[j].contador==letras[menor].contador && letras[j].asc>letras[menor].asc)
                    menor=j;
            }
            aux=letras[i];
            letras[i]=letras[menor];
            letras[menor]=aux;
        }
        i=0;
        if(flag==1) printf("\n");
        for(i=0;i<129;i++){
            if(letras[i].contador!=0) printf("%d %d\n",letras[i].asc,letras[i].contador);
        }
        flag=1;
    }
    return 0;
}
