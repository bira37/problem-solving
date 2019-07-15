#include <bits/stdc++.h>

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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

map<int, int> cnt[112345];
vector<int> adj[112345];
long long sum[112345];
long long qtd[112345];
long long ans[112345];

void dfs(int u, int p){
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
    if(qtd[v] > qtd[u]){
      sum[u] = sum[v];
      qtd[u] = qtd[v];
    }
    else if(qtd[v] == qtd[u]){
      sum[u] += sum[v];
    }
    if(cnt[v].size() > cnt[u].size()) swap(cnt[u], cnt[v]);
    for(auto it : cnt[v]){
      cnt[u][it.ff] += it.ss;
      if(cnt[u][it.ff] > qtd[u]){
        qtd[u] = cnt[u][it.ff];
        sum[u] = it.ff;
      }
      else if(cnt[u][it.ff] == qtd[u] && it.ss != cnt[u][it.ff]){
        sum[u] += it.ff;
      }
    }  
  }
  ans[u] = sum[u];   
}

int32_t main(){
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    int c;
    scanf("%d", &c);
    cnt[i][c] = 1;
    sum[i] = c;
    qtd[i] = 1;
  }
  for(int i=1; i<=n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, -1);
  for(int i=1; i<=n; i++) printf("%lld ", ans[i]);
  puts("");
}