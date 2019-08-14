#include <stdio.h>
#include <string.h>

int main() {
	char tel[16];
	int i,tam;
	tam=strlen(tel);
	scanf("%s",tel);
	for(i=0;i<strlen(tel);i++){
		if (tel[i] >= 'A' && tel[i] <= 'C')
			tel[i]='2';
		else if(tel[i] >='D' && tel[i] <= 'F')
			tel[i]='3';
		else if(tel[i] >='G' && tel[i] <= 'I')
			tel[i]='4';
		else if(tel[i] >='J' && tel[i] <= 'L')
			tel[i]='5';
		else if(tel[i] >='M' && tel[i] <= 'O')
			tel[i]='6';
		else if(tel[i] >='P' && tel[i] <= 'S')
			tel[i]='7';
		else if(tel[i] >='T' && tel[i] <= 'V')
			tel[i]='8';
		else if(tel[i] >='W' && tel[i] <= 'Z')
			tel[i]='9';
	}
	printf("%s\n",tel);
	return 0;
}
			

