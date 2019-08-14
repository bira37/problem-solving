#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m9(char *num){
	int s=0;
	int t=strlen(num);
	int i;
	for(i=0;i<t;i++)s+=((int)num[i]-48);
	if(s%9==0) return 1;
	else return 0;
}

int g9(char *num){
	int size=strlen(num);
	if(size!=1){
		int s=0,i;
		for(i=0;i<size;i++) s+=(int)num[i]-48;
		sprintf(num,"%d",s);
		return 1+g9(num);
	}
	else return 0;
}
			
int main(){
	char num[1000];
	while(scanf("%s",num), strlen(num)!=1 || num[0]!='0'){
		char num2[strlen(num)];
		strcpy(num2,num);
		int x=m9(num2);
		if(x){
			int y=g9(num2);
			if(!y) y=1;
			printf("%s is a multiple of 9 and has 9-degree %d.\n",num,y);
		}
		else printf("%s is not a multiple of 9.\n",num);
	}
	return 0;
}
		

