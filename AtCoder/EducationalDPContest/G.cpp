#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define INF 1000000007
#define MAXN 100100
using namespace std;

vector<int> saida[MAXN];
vector<int> chega[MAXN];

int best[MAXN];

int go(int v){
	if(best[v]!=-1)return best[v];
	int res=0;
	for(int i=0;i<saida[v].size();i++){
		int u = saida[v][i];
		res=max(res,1+go(u));
	}		 			
	return best[v]=res;
}


int32_t main(){
	int n,m;
	cin>>n>>m;
	int a,b;
	memset(best,-1,sizeof(best));
	for(int i=0;i<m;i++){
		cin>>a>>b;
		saida[a].push_back(b);
		chega[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		if(saida[i].size()==0)best[i]=0;
	}
	for(int i=1;i<=n;i++){
		go(i);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,best[i]);
	}
		   cout<<res<<endl;	   	
}
