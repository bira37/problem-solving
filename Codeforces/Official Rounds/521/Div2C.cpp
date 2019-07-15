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
  int n;
  cin >> n;
  ii v[n+2];
  for(int i=2; i<=n+1; i++){
    cin >> v[i].ff;
    v[i].ss = i-1;
  }
  sort(v+2, v+n+2);
  int p[n+2];
  p[0] = p[1] = 0;
  for(int i=2; i<=n+1; i++){
    p[i] = p[i-1] + v[i].ff;
  }
  vector<int> ans;
  for(int i=2; i<=n; i++){
    if(p[i-1] + max(0LL, (p[n] - p[i])) == p[n+1] - p[n]) ans.pb(v[i].ss);
  }
  if(p[n-1] == p[n] - p[n-1]) ans.pb(v[n+1].ss);
  cout << ans.size() << endl;
  for(int x : ans) cout << x << " ";
  cout << endl;  
}

