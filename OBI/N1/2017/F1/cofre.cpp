#include <bits/stdc++.h>
#define MAXN 100100
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int times[MAXN][10];
int num[10];
int main(){
	fastio;
	int n,m,aux;
	cin>>n>>m;
	
		
	for(int i=0;i<10;i++){num[i]=0;
	times[0][i]=0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>aux;
		for(int j=0;j<10;j++){
			times[i][j]=times[i-1][j];
		}
		times[i][aux]++;
	}
	
	int ini = 1;
	int agr;
	
	for(int j=0;j<10;j++){
		num[j]+=times[1][j];
	}
	
	for(int i=0;i<m;i++){
		cin>>agr;
		if(agr==ini)continue;
		if(agr>ini){
			
			for(int j=0;j<10;j++){
				num[j]+=times[agr][j]-times[ini][j];//rever o -1
			}
			
		}else if(agr<ini){
			for(int j=0;j<10;j++){
				num[j]+=times[ini-1][j]-times[agr-1][j];
			}
			
		}
		ini = agr;
	}
	
	for(int i=0;i<10;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
}