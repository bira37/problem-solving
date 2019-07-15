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

ii v[112345];
int n,x,y;

int32_t main(){
  DESYNC;
  cin >> n;
  cin >> x >> y;
  for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
  sort(v,v + n);
  int ans = 0;
  multiset< int > s;
  int bst = x/y;
  for(int i=0; i<n; i++){
    auto it = s.upper_bound(-v[i].ff);
    if(it == s.end()){
      s.insert(-v[i].ss);
      ans += x + y*(v[i].ss - v[i].ff);
      ans = mod(ans, M);
    }
    else {
      int k = -1*(*it);
      if(bst >= v[i].ff - k){
        s.erase(it);
        ans += y*max(0LL, v[i].ss - k);
        ans = mod(ans, M);
        s.insert(-max(k, v[i].ss));
      }
      else {
        s.insert(-v[i].ss);
        ans += x + y*(v[i].ss - v[i].ff);
        ans = mod(ans, M);
      }
    }
  }
  cout << ans << endl;
}

