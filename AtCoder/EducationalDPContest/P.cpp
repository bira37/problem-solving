#include <bits/stdc++.h>
#define MAXN 100100
#define int long long
#define M 1000000007
using namespace std;
int dp[MAXN][2];
int pai[MAXN];
vector<int> vizinhos[MAXN];

inline int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}

void DFS(int x,int p){
	for(int i=0;i<vizinhos[x].size();i++){
		int u = vizinhos[x][i];
		if(u==p)continue;
		pai[u]=x;
		DFS(u,x);
	}
}

int solve(int id,int paiP){
	if(dp[id][paiP]!=-1)return dp[id][paiP];
	int caso1=1;//pai foi pintado
	int caso2=1;
	int flag = true;
	
	for(int i=0;i<vizinhos[id].size();i++){
		
		int u = vizinhos[id][i];
		
		if(u==pai[id])continue;
		flag = false;
		caso1=mod(caso1*solve(u,0),M);   	
		caso2=mod(caso2*solve(u,1),M);   	
	}	
		 			  		  
	if(paiP==1){
		return dp[id][paiP]=mod(caso1,M);
	}
	return dp[id][paiP]=mod(caso1+caso2,M);	
}



int32_t main(){
	int n;
	cin>>n;
	int x,y;
	memset(dp,-1,sizeof(dp));
	
	for(int i=1;i<n;i++){
		cin>>x>>y;
		vizinhos[x].push_back(y);
		vizinhos[y].push_back(x);
	}
	
	pai[1]=-1;
	DFS(1,-1);
	cout<<solve(1,0)<<endl;		
}
