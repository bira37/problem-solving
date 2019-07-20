#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ieps (int) 1e6
#define eps (int) 1e9
#define pii pair<int,int>
#define int long long
int n;
vector<int> adj[ieps];
int ans = -1 , nodeans = -1;
void dfs(int x  , int pai , int andou){
	if(andou > ans ){
		ans = andou;
		nodeans = x;
	}
	for(auto p : adj[x]){
		if(p == pai) continue;
		dfs(p , x , andou + 1);
	}
}
 
int32_t main(){
	scanf("%lld"  , &n);
	int rootdef = -1;
	for(int  i = 0 ;i<n - 1;i++){
		int x , y;
		scanf("%lld%lld" , &x  ,&y);
		x-- , y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i = 0;i<n;i++){
		if(adj[i].size() == 1) rootdef = i;
	}
	dfs(rootdef , rootdef , 0);
	ans = -1;
	dfs(nodeans , nodeans , 0);
	int j = 0;
 
	for(int i = 0 ; i <= 20 ; i++){
		if((1LL<<i) >= ans){
			printf("%lld\n" , i);
			return 0;
		}
	}
}
