#include <bits/stdc++.h>

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

int uf[512345];
int sz[512345];

int find(int u){
  if(uf[u] == u) return u;
  uf[u] = find(uf[u]);
  return uf[u];
}

void merge(int a, int b){
  int x = find(a), y = find(b);
  if(x == y) return;
  if(sz[x] < sz[y]) swap(x,y);
  uf[y] = x;
  sz[x] += sz[y];
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    uf[i] = i;
    sz[i] = 1;
  }
  for(int i=0; i<m; i++){
    int k;
    cin >> k;
    if(k == 0) continue;
    int leader;
    cin >> leader;
    k--;
    for(int j=0; j<k; j++){
      int x;
      cin >> x;
      merge(leader, x);
    }
  }
  for(int i=1; i<=n; i++) cout << sz[find(i)] << " ";
  cout << endl;
}

