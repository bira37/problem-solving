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
 
struct edge{
  int u,v,x,id;
  edge() {}
  edge(int u, int v, int x, int id) : u(u), v(v), x(x), id(id) {}
};
 
vector< ii > g[1123];
int dist[1123];
int p[1123];
vector<int> nulls;
edge prt[11234];
int n,m,L,startt,endd;
 
int dij(int limit, int change = 1){
  for(int i=0; i<=n; i++) dist[i] = INF;
  dist[startt] = 0;
  set< ii > s;
  s.insert(ii(dist[startt], startt));
  while(!s.empty()){
    int cur, track;
    cur = s.begin()->ss;
    track = s.begin()->ff;
    s.erase(s.begin());
    if(dist[cur] < track) continue;
    //cout << cur << " " << dist[cur] << endl;
    for(ii e : g[cur]){
      int label = e.ss;
      int v = e.ff;
      int cost = prt[label].x;
      if(prt[label].id < limit and prt[label].id >= 0 and dist[v] > 1 + track){
        dist[v] = 1 + track;
        s.insert(ii(dist[v], v));
      }
      else if(prt[label].id == limit and prt[label].id >= 0 and dist[v] > change + track){
        dist[v] = change + track;
        s.insert(ii(dist[v], v));
      }
      else if(prt[label].id > limit and prt[label].id >= 0 and dist[v] > L+10 + track){
        dist[v] = L+10 + track;
        s.insert(ii(dist[v], v));
      }
      else if(prt[label].id < 0 and dist[v] > cost + track){
        dist[v] = track + cost;
        s.insert(ii(dist[v], v));
      }
    }
  }
  return dist[endd];
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m >> L >> startt >> endd;
  for(int i=0; i<m; i++){
    int u,v,c;
    cin >> u >> v >> c;
    int id = -2;
    if(c == 0){
      id = nulls.size();
      nulls.pb(i);
    }
    prt[i] = edge(u,v,c,id);
    g[u].pb(ii(v,i));
    g[v].pb(ii(u,i));
  }
  
  //cout << endl << endl;
  if(dij(-1) < L){
    cout << "NO" << endl;
    return 0;
  }
  
  int l = 0, r = (int)(nulls.size())-1;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    //cout << "check " << m << " " << endl;
    if(dij(m) <= L){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  //cout << ans << endl;
  int ululu = ans;
  l = 1, r = L;
  ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(dij(ululu, m) <= L){
      ans = m;
      l = m+1;
    }
    else r = m-1;
  }
  
  if(ans == -1){
    cout << "NO" << endl;
    return 0;
  }
  
  cout << "YES" << endl;
  for(int i=0; i<m; i++){
    if(prt[i].id == ululu and prt[i].id >= 0) prt[i].x = ans;
    else if(prt[i].id < ululu and prt[i].id >= 0) prt[i].x = 1;
    else if(prt[i].id > ululu and prt[i].id >= 0) prt[i].x = L+10;
    cout << prt[i].u << " " << prt[i].v << " " << prt[i].x << endl;
  }
}
 
