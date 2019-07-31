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

/* Z-function */
/* Calculate the size K of the largest substring which is a prefix */

struct ZFunction{

  vector<int> z;
  
  ZFunction() {}
  
  void calculate(string t){
    int n = t.size();
    z.resize(n);
    z[0] = 0;
    int l = 0, r = 0;
    for(int i=1; i<n; i++){
      if(i > r){
        l = i;
        r = i;
      }
      z[i] = min(z[i-l], r-i+1);
      while(i + z[i] < n && t[i + z[i]] == t[z[i]]) z[i]++;
      if(i + z[i] > r){
        l = i;
        r = i + z[i]-1;
      }
    }
  }
  
};

vector<int> g[2123456];
bool mrk[2123456];
int vis[2123456];
bool cycle;
int w;

void go(int u, int p){
  vis[u] = 1;
  w++;
  for(int v : g[u]){
    if(v == p) continue;
    if(vis[v]) cycle = true;
    else if(vis[v] == 0) go(v, u);
  }
}

int32_t main(){
  DESYNC;
  string s,t;
  cin >> s >> t;
  string z = s;
  while(z.size() < t.size()) z += z;
  s = z;
  z = t + "#" + z + z;
  //cout << z << endl;
  ZFunction zeta;
  zeta.calculate(z);
  int cnt = 0;
  int cur = t.size()+1;
  
  for(int i=0; i<s.size(); i++){
    if(zeta.z[i+cur] == t.size()){
      mrk[i] = true;
      //cout << "mark " << i << endl;
    }
  }
  
  for(int i=0; i<s.size(); i++){
    if(mrk[i] and mrk[(i+t.size())%(int)(s.size())]){
      g[i].pb((i+t.size())%(int)(s.size()));
      g[(i+t.size())%(int)(s.size())].pb(i);
      //cout << "edge" << endl;
      //cout << i << " " << (i+t.size())%(int)(s.size()) << endl;
    }
  }
  cycle = false;  
  int walk = 0;
  for(int i=0; i<s.size(); i++){
    if(vis[i] == 0 and mrk[i]){
      w = 0;
      go(i, -1);
      walk = max(w, walk);
    }
  }
  if(cycle) cout << -1 << endl;
  else cout << walk << endl;
}


