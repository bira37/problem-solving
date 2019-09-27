#include <bits/stdc++.h>
#define MAXN 3500
using namespace std;

int LCS[MAXN][MAXN];
char L[MAXN];

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int x = s1.size();
	int y = s2.size();
	int i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<=y;j++){
			if(i==0 || j==0)LCS[i][j]=0;
			else if(s1[i-1]==s2[j-1]){
				LCS[i][j]=1+LCS[i-1][j-1];
			}else{
				LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
			}
		}

	int index = LCS[x][y];
	L[index+1]='\0';
	
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			L[index]=s1[i-1];
			i--;j--;index--;
		}else{
			if(LCS[i][j-1]>LCS[i-1][j]){
				j--;
			}else i--;
			
		}
		
	}
	cout<<L<<endl;
}
