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
 
bool cmp(ii a, ii b) {
  return a.ss > b.ss;
}
 
 
int32_t main(){
  DESYNC;
  
  int n;
  cin >> n;
  
  vii p(n);
  int lim = -INT_MAX;
  for(int i = 0; i < n; i++) {
    cin >> p[i].ff >> p[i].ss; 
    lim = max(lim, p[i].ff);
  }
  
  sort(p.begin(), p.end(), cmp);
  //reverse(p.begin(), p.end());
  
  
  //int l = p[0].ff;
  int ans = 0;
  //cout << lim << endl;
  for(int i = 0; i < n; i++) {
    //cout << p[i].ss << endl;
    if(p[i].ss >= lim) {
      ans++;
    } else {
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  
}
 
