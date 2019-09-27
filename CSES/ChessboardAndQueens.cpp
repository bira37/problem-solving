#include <bits/stdc++.h>
#define F(i,n) for(int i=1;i<=n;i++)
using namespace std;
char s[10][10];
int r[20];
int c(int num,int j){
	if(s[num][j]=='*')return 0;
	F(x,num-1){
		if(j==r[x])return 0;
		if(abs(x-num)==abs(j-r[x]))return 0;
	}
	return 1;
}
 
int go(int num){
	if(num==9)return 1;
	int a=0;
	F(j,8){
		if(c(num,j)){
			r[num]=j;
			a+=go(num+1);
		}
	}
	return a;
}
 
int main(){
	   F(i,8)F(j,8)
	   	cin>>s[i][j];
	   cout<<go(1)<<endl;
}