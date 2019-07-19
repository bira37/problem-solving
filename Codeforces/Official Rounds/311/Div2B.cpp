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
 
int v[212345];
int n, w;
 
bool check(double x){
  double k = x/(3.*n);
  for(int i=0; i<n; i++){
    if(k > v[i]) return false;
  }
  for(int i=n; i<2*n; i++){
    if(2.*k > v[i]) return false;
  }
  return true;
}
 
int32_t main(){
  DESYNC;
  cin >> n >> w;
  double l = 0, r = w;
  for(int i=0; i<2*n; i++){
    cin >> v[i];
  }
  sort(v, v+2*n);
  double ans = 0.0;
  for(int it = 0; it < 200; it++){
    double m = (l+r)/2.;
    if(check(m)){
      ans = m;
      l = m;
    }
    else r = m;
  }
  cout << fixed << setprecision(9) << ans << endl;
}
 
