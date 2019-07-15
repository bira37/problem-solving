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
 
ii v[112345];

bool check(int m, int n){
  //(m, 0) (0,m)
  for(int i=0; i<n; i++){
    ii v1(m - v[i].ff, 0 - v[i].ss);
    ii v2(-v[i].ff, m - v[i].ss);
    if(v1.ff*v2.ss - v1.ss*v2.ff < 0) return false;
  }
  return true;
} 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int ans = 0;
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    ans = max(ans, x+y);
  }
  cout << ans << endl;
}

