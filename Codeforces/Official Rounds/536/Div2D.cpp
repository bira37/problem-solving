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
bool vis[112345];

int32_t main(){
  DESYNC;
  int n, m;
  cin >> n >> m;
  set<int> s;
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  s.insert(1);
  vis[1] = true; 
  while(!s.empty()){
    int cur = *s.begin();
    s.erase(s.begin());
    cout << cur << " ";
    for(int v : adj[cur]){
      if(!vis[v]){
        vis[v] = true;
        s.insert(v);
      }
    }
  }
  cout << endl;
}

