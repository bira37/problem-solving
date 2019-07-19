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
 
int PA(int n){
  return (n*(n+1))/2;
}
 
int32_t main(){
  DESYNC;
	int t;
  cin >> t;
  while(t--){
    int n,a;
    cin >> n >> a;
    int need = n*a;
    int l = 0, r = n;
    int ans = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(need - PA(m) >= n - m){
        ans = m;
        l = m+1;
      }
      else r = m-1;
    }
    cout << ans << endl;
  }
}
