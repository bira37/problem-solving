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
 
struct submission{
  int team, prob, judge;
  string tempo;
  bool operator<(const submission & b) const{
    return tempo < b.tempo;
  }
};
 
struct edge{
  int u,v,c;
  bool operator<(const edge & b) const{
    return c < b.c;
  }
};
 
int uf[20];
int sz[20];
int init(int n){
  for(int i=0; i<=n; i++){
    uf[i] = i;
    sz[i] = 1;
  }
}
 
int find(int u){
  if(uf[u] == u) return u;
  else return uf[u] = find(uf[u]);
}
 
void join(int u, int v){
  int a = find(u);
  int b = find(v);
  if(sz[a] < sz[b]) swap(a,b);
  sz[a] += sz[b];
  uf[b] = a;
}
 
int32_t main(){
  DESYNC;
	int t;
  cin >> t;
  while(t--){
    int n,m,k;
    cin >> n >> m >> k;
    edge act[m];
    
    int imp[k];
    for(int i=0; i<m; i++){
      cin >> act[i].u >> act[i].v >> act[i].c;
    }
    for(int i=0; i<k; i++) cin >> imp[i];
    
    sort(act, act+m);
    int ans = INT_MAX;
    for(int msk = 1; msk < (1<<n); msk++){
      vector<edge> g;
      bool ok = true;
      for(int i=0; i<k; i++){
        if(!(msk & (1<<(imp[i]-1)))){
          //cout << "subset " << msk << " doesnt contain " << imp[i] << endl;
          ok = false;
          break;
        }
      }
      //cout << "taking subset " << msk << endl;
      if(!ok) continue;
      //cout << "going" << endl;
      int vertex = __builtin_popcount(msk);
      for(int i=0; i<m; i++){
        if((msk & (1 << (act[i].u-1))) && (msk & (1 << (act[i].v-1)))){
          g.push_back(act[i]);
        }
      } 
      
      int cnt = 0;
      int cur = 0;
      init(n);
      
      for(edge e : g){
        if(find(e.u) == find(e.v)) continue;
        cnt++;
        cur += e.c;
        join(e.u, e.v);
      }
      if(cnt == vertex-1) ans = min(ans, cur);
    }
    cout << ans << endl;
  }
}
