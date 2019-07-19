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
#define INF 2e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct pt{
  double x, y;
  pt() {}
  pt(double x, double y) : x(x), y(y) {}
};
 
int n;
pt v[212345];
 
bool check(double m){
  //cout << "check " << m << endl;
  vector< pair<double, double> > seg;
  for(int i=0; i<n; i++){
    double a = m;
    double b = abs(m - v[i].y);
    if(b > m) return false;
    double c = (a-b)*(a+b);
    c = sqrtl(c);
    seg.pb(mp(v[i].x - c, v[i].x + c));
  }
  double l = -INF, r = INF;
  for(auto p : seg){
    l = max(l, p.ff);
    r = min(r, p.ss);
  }
  if(l <= r) return true;
  else return false;
}  
 
int32_t main(){
  DESYNC;
  cin >> n;
  bool neg = false, pos = false;
  for(int i=0; i<n; i++){
    cin >> v[i].x >> v[i].y;
    if(v[i].y < 0) neg = true;
    else pos = true;
  }
  if(neg && pos){
    cout << -1 << endl;
    return 0;
  }
  if(neg){
    for(int i=0; i<n; i++) v[i].y *= -1;
  }
  double l = 0.0, r = 1e16;
  double ans = -1;
  for(int iter = 0; iter < 200; iter++){
    double m = (l+r)/2.;
    if(check(m)){
      ans = m;
      r = m;
    }
    else l = m;
  }
  cout << fixed << setprecision(15) << ans << endl;
}
 
