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

vector<int> g[112345];
int s[212345];
int a[212345];

int go(int u, int lst){
  int val = INF;
  for(int v : g[u]){
    int x = go(v, (s[u] != -1 ? s[u] : lst));
    val = min(val, (int)(x >= 0 ? x : INF));
  }
  if(s[u] > val){
    cout << -1 << endl;
    exit(0);
  }
  if(s[u] == -1) s[u] = (val != INF ? val : lst);
  //cout << u << " " << s[u] << endl;
  return s[u];
}

void solve(int u, int sum){
  a[u] = s[u] - sum;
  if(a[u] < 0){
    cout << -1 << endl;
    exit(0);
  }
  for(int v : g[u]){
    solve(v, sum + a[u]);
  }
}
    
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=2; i<=n; i++){
    int x;
    cin >>x;
    g[x].pb(i);
  }
  for(int i=1; i<=n; i++) cin >> s[i];
  if(s[1] == -1){
    cout << -1 << endl;
    return 0;
  }
  go(1, s[1]);
  solve(1, 0);
  int sum = 0;
  for(int i=1; i<=n; i++) sum += a[i];
  cout << sum << endl;      
}

