#include <bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
#define M 1000000007
#define pb push_back
#define endl '\n'
using namespace std;

typedef long long ll;

vector<int> adj[11234];
int c[11234];
int ans = 0;
int solve(int u, int color){
	if(color != c[u]) ans++;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		solve(v, c[u]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for(int i=2; i<=n; i++){
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	
	for(int i=1; i<=n; i++) cin >> c[i];
	
	solve(1,0);
	
	cout << ans << endl;
}