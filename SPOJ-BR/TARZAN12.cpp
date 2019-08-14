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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

vector< ii > v;
vector< bool > vis;
int tot = 0;
int d;

int dist(ii a, ii b){
  return (a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss);
}

void go(int u){
  vis[u] = true;
  tot++;
  for(int i=0; i<v.size(); i++){
    if(vis[i]) continue;
    if(dist(v[u], v[i]) > d*d) continue;
    go(i);
  }
}
  
int32_t main(){
  DESYNC;
  int n;
  cin >> n >> d;
  v.resize(n);
  vis.resize(n);
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    v[i] = ii(x,y);
  }
  go(0);
  if(tot == n) cout << "S" << endl;
  else cout << "N" << endl;
}


