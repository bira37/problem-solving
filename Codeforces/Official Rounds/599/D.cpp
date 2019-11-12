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

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  set<int> g[n+1];
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  set<ii> s;
  int cnt[n+1];
  int ans = 0;
  for(int i=1; i<=n; i++){
      s.insert(ii(0, i));
      cnt[i] = 0;
  }
  int vis = 0;
  while(s.size() > 0){
    int c = s.begin()->ff;
    int u = s.begin()->ss;
    s.erase(s.begin());
    if(vis == c){
      ans++;
      //cout << "nova comp" << endl;
    }
    //cout << u << endl;
    vis++;
    for(int v : g[u]){
      if(s.count(ii(cnt[v], v))){
        s.erase(ii(cnt[v], v));
        cnt[v]++;
        s.insert(ii(cnt[v], v));
      }
    }
  }
  cout << ans-1 << endl;
}

 
