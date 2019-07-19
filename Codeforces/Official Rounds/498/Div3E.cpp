#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
vector<int> adj[212345];
vector<int> order;
int st[212345];
int subsz[212345];
int tempo = 0;
 
void go(int u, int p){
	order.pb(u);
	st[u] = tempo++;
	subsz[u] = 1;
	for(int v : adj[u]){
		if(v == p) continue;
		go(v,u);
		subsz[u] += subsz[v];
	}
}
 
int32_t main(){
  DESYNC;
  int n, q;
  cin >> n >> q;
  for(int i=2; i<=n; i++){
  	int p;
  	cin >> p;
  	adj[p].pb(i);
  }
  for(int i=1; i<=n; i++){
  	sort(adj[i].begin(), adj[i].end());
  }
  go(1,-1);
  while(q--){
  	int u, k;
  	cin >> u >> k;
  	if(k > subsz[u]) cout << -1 << endl;
  	else cout << order[st[u] + k-1] << endl;
  }
  
}
 
