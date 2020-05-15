#include <stdio.h>

int conversao_romano(int centena,int dezena,int unidade){
    if(centena==1)
        printf("C");
    else if(centena==2)
        printf("CC");
    else if(centena==3)
        printf("CCC");
    else if(centena==4)
        printf("CD");
    else if(centena==5)
        printf("D");
    else if(centena==6)
        printf("DC");
    else if(centena==7)
        printf("DCC");
    else if(centena==8)
        printf("DCCC");
    else if(centena==9)
        printf("CM"); //até aqui, a parte da centena do número é convertida em romano
    if(dezena==1)
        printf("X");
    else if(dezena==2)
        printf("XX");
    else if(dezena==3)
        printf("XXX");
    else if(dezena==4)
        printf("XL");
    else if(dezena==5)
        printf("L");
    else if(dezena==6)
        printf("LX");
    else if(dezena==7)
        printf("LXX");
    else if(dezena==8)
        printf("LXXX");
    else if(dezena==9)
        printf("XC"); //essa parte converte a dezena do numero em romano
    if(unidade==1)
        printf("I");
    else if(unidade==2)
        printf("II");
    else if(unidade==3)
        printf("III");
    else if(unidade==4)
        printf("IV");
    else if(unidade==5)
        printf("V");
    else if(unidade==6)
        printf("VI");
    else if(unidade==7)
        printf("VII");
    else if(unidade==8)
        printf("VIII");
    else if(unidade==9)
        printf("IX"); //aqui convertemos a parte da unidade
	return 0;
}

int main() {
    int numeroArabico,unidade,dezena,centena;
    scanf("%d",&numeroArabico);
    centena=(numeroArabico/100);
    dezena=(numeroArabico/10)%10;
    unidade=numeroArabico%10;
    conversao_romano(centena,dezena,unidade); //uso a função de conversão para converter o número e imprimir
    printf("\n");
	return 0;
}
    
