#include <stdio.h>
 
int main() {
    int h1,m1,h2,m2;
    int h=0,m=0;
    scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
 	if(h2>=h1) h=h2-h1;
	else {
		h=24-h1;
		if(h==24) h=0;
		h=h+h2;
	}
	if(h==0) h=24;
	if(m2>=m1) m=m2-m1;
	else {
		m=60-m1;
		if(m==60) m=0;
		h--;
		m=m+m2;
	}
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h,m);
    return 0;
}
