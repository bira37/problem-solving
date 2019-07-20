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
  ii v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].ff >> v[i].ss;
  }
  sort(v, v+n, *[](const ii & a, const ii & b){
    return a.ff - a.ss > b.ff - b.ss;
  });
  int need = 0;
  int ans = 0;
  for(int i=0; i <n; i++){
    if(need < v[i].ff){
      ans += v[i].ff - need;
      need = v[i].ff;
    }
    need -= v[i].ss;
  }
  cout << ans << endl;
}
 
