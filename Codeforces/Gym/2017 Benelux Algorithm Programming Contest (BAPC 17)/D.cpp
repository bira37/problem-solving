#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
vector< ii > adj[112345];
int d[112345];
vector<int> ans;
bool flag = false;
bool vis[112345];
 
void go(int u){
  if(u == 1){
    flag = true;
    ans.pb(1);
    return;
  }
  vis[u] = true;
  for(ii ad : adj[u]){
    int v = ad.first;
    int cost = ad.second;
    if(d[u] - d[v] != cost && !vis[v]){
      go(v);
      if(flag){
        ans.pb(u);
        return;
      }
    }
  }
}
      
int32_t main(){
	DESYNC;
	int n,m;
	cin >> n >> m;
	for(int i=0; i<=n; i++){
	  d[i] = (int)1e15;
	  vis[i] = false;
	}
	for(int i=0; i<m; i++){
	  int u, v, c;
	  cin >> u >> v >> c;
	  adj[u].pb(ii(v,c));
	  adj[v].pb(ii(u,c));
	}
	set< ii > s;
	d[1] = 0;
	s.insert(ii(0, 1));
	while(!s.empty()){
	  int u = s.begin()->second;
	  int dst = s.begin()->first;
	  s.erase(s.begin());
	  if(dst != d[u]) continue;
	  for(ii ad : adj[u]){
	    int cost = ad.second;
	    int v = ad.first;
	    if(dst + cost <= d[v]){
	      d[v] = dst+cost;
	      s.insert(ii(d[v],v));
	    }
	  }
	}
	go(0);
	if(flag){
	  reverse(ans.begin(), ans.end());
	  cout << ans.size();
	  for(int x : ans) cout << " " << x;
	  cout << endl;
	}
	else cout << "impossible" << endl;
}
 
