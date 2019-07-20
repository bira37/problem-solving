#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
vector<int> adj[112345];
vector<int> cycle1, cycle2;
bool vis[112345];
int n,m;
bool test(int a, int b){
  queue<int> q1, q2;
  cycle1.clear(), cycle2.clear();
  for(int i=0; i<112345; i++) vis[i] = false;
  q1.push(a);
  q2.push(b);
  vis[a] = true;
  vis[b] = true;
  while(!q1.empty() || !q2.empty()){
    if(!q1.empty()){
      int cur = q1.front();
      q1.pop();
      cycle1.pb(cur);
      for(int v : adj[cur]) if(!vis[v]){
        q1.push(v);
        vis[v] = true;
      }
    }
    if(!q2.empty()){
      int cur = q2.front();
      q2.pop();
      for(int v : adj[cur]) if(!vis[v]){
        q2.push(v);
        vis[v] = true;
      }
    }
  }
  queue<int> q;
  set<int> s;
  for(int x : cycle1) s.insert(x);
  q.push(a);
  s.erase(s.find(a));
  cycle1.clear();
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    cycle1.pb(cur);
    for(int v : adj[cur]){
      if(s.count(v)){
        s.erase(s.find(v));
        q.push(v);
        break;
      }
    }
  }
  if(cycle1.size() == n/2){
    for(int i=0; i<112345; i++) vis[i] = false;
    for(int x : cycle1) vis[x] = true;
    for(int x : cycle1){
      for(int v : adj[x]){
        if(!vis[v]){
          vis[v] = true;
          cycle2.pb(v);
          break;
        }
      }
    }
    if(cycle2.size() != n/2) return false;
    bool ok = true;
    for(int i=0; i<cycle2.size(); i++){
      int prv = ((i-1)%(int)cycle2.size() + (int)cycle2.size())%(int)cycle2.size();
      int nxt = (i+1)%cycle2.size();
      bool f1 = false, f2 = false;
      for(int v : adj[cycle2[i]]){
        if(cycle2[prv] == v) f1 = true;
        if(cycle2[nxt] == v) f2 = true;
      }
      if(!f1 || !f2) ok = false;
    }
    return ok;
  }
  else return false;
}
 
int32_t main(){
	DESYNC;
	cin >> n;
	m = 3*n/2;
	for(int i=0; i<m; i++){
	  int u,v;
	  cin >> u >> v;
	  adj[u].pb(v);
	  adj[v].pb(u);
	}
	for(int v : adj[1]){
	  if(test(1, v)){
	    cout << "YES" << endl;
	    for(int i=0; i<cycle1.size(); i++){
	      if(i) cout << " ";
	      cout << cycle1[i];
	    }
	    cout << endl;
	    for(int i=0; i<cycle2.size(); i++){
	      if(i) cout << " ";
	      cout << cycle2[i];
	    }
	    cout << endl;
	    return 0;
	  }
	}
	cout << "NO" << endl;
}
 
