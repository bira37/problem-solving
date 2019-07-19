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
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector< ii > v(n);
  for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
  sort(v.begin(), v.end());
  int pos = 0;
  int neg = 0;
  for(ii x : v) if(x.ff > 0) pos++; else neg++;
  int it = min(pos, neg);
  int start = n;
  for(int i=0; i<n; i++) if(v[i].ff > 0){
    start = i;
    break;
  }
  int ans = 0;
  for(int i=start; i < n && i <= start + it; i++){
    ans += v[i].ss;
  }
  for(int i=start-1; i >= 0 && i>= (start - it - 1); i--){
    ans += v[i].ss;
  }
  cout << ans << endl;
  
}
 
