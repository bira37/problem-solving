#include <bits/stdc++.h>
 
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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
vector<int> adj[512345];
vector<int> dep[512345];
char letter[512345];
vector< bitset<26> > cnt[512345];
int in[512345], out[512345];
int level[512345];
int tempo = 0;
bitset<26> dummy;
 
void go(int u, int l){
  in[u] = tempo++;
  level[u] = l;
  dep[l].pb(u);
  dummy.reset();
  dummy[letter[u] - 'a'] = true;
  cnt[l].pb(dummy);
  for(int v : adj[u]){
    go(v, l+1);
  }
  out[u] = tempo++;
}
 
bool is_sub(int u, int v){
  return in[v] <= in[u] && out[u] <= out[v];
}
 
int find_l(int v, int h){
  int l = 1, r = (int)(dep[h].size())-1;
  int ans = 0;
  while(l <= r){
    int m = (l+r)>>1;
    if(is_sub(dep[h][m], v)){
      ans = m-1;
      r = m-1;
    }
    else if(in[dep[h][m]] < in[v]) l = m+1;
    else r = m-1;
  }
  return ans;
}
 
int find_r(int v, int h){
  int l = 1, r = (int)(dep[h].size())-1;
  int ans = 0;
  while(l <= r){
    int m = (l+r)>>1;
    if(is_sub(dep[h][m], v)){
      ans = m;
      l = m+1;
    }
    else if(in[dep[h][m]] < in[v]) l = m+1;
    else r = m-1;
  }
  return ans;
}
 
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  for(int i=2; i<=n; i++){
    int p;
    cin >> p;
    adj[p].pb(i);
  }
  for(int i=1; i<=n; i++){
    cin >> letter[i];
    dep[i].pb(0);
    cnt[i].pb(dummy);
  }
  go(1, 1);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=(int)cnt[i].size()-1; j++){
      cnt[i][j] = (cnt[i][j]^cnt[i][j-1]);
    }
  }
  while(q--){
    int v,h;
    cin >> v >> h;
    if(h <= level[v]) cout << "Yes" << endl;
    else {
      int l = find_l(v, h);
      int r = find_r(v, h);
      auto ans = (cnt[h][r]^cnt[h][l]);
      int par = 0;
      for(int i=0; i<26; i++){
        if(ans[i]) par++;
      }
      if(par < 2) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
 
