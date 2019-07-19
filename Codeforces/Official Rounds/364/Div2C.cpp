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
  set<int> s[256];
  int n;
  cin >> n;
  string t;
  cin >> t;
  for(int i=0; i<n; i++){
    s[t[i]].insert(i);
  }
  int ans = n;
  for(int i=0; i<n; i++){
    int mx = 0;
    bool ok = true;
    for(char c = 'A'; c <= 'z'; c++){
      if(s[c].size() == 0) continue;
      auto it = s[c].lower_bound(i);
      if(it == s[c].end()){
        ok = false;
        break;
      }
      //cout << "for " << i << " " << c << " " << *it << endl;
      mx = max(mx, *it);
    }
    if(ok) ans = min(ans, mx - i + 1);
  }
  cout << ans << endl;
}
 
