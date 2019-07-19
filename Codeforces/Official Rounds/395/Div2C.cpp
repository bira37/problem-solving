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
 
vector<int> adj[112345];
int c[112345];
 
bool go(int u, int p){
	bool ok = true;
	for(int v : adj[u]){
		if(v == p) continue;
		if(c[u] != c[v]) return false;
		ok &= go(v,u);
	}
	return ok;
}
 
bool check(int u){
	bool ok = true;
	for(int v : adj[u]){
		ok &= go(v, u);
	}
	return ok;
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
  	int u,v;
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for(int i=1; i<=n; i++) cin >> c[i];
  for(int i=1; i<=n; i++){
  	for(int v : adj[i]){
  		if(c[i] != c[v]){
  			if(check(i)){
  				cout << "YES\n" << i << endl;
  				return 0;
  			}
  			else if(check(v)){
  				cout << "YES\n" << v << endl;
  				return 0;
  			}
  			else{
  				cout << "NO" << endl;
  				return 0;
  			}
  		}
  	}
  }
  cout << "YES" << endl << 1 << endl;
}
 
