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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
ii inverse(int x, int y){
  return ii((x+y)/2, x - (x+y)/2);
}
 
ii convert(int x, int y){
  return ii(x+y, x-y);
}
 
ii v[1123];
int d[1123];
 
int n;
 
bool check(int x, int y){
  bool ok = true;
  for(int i=0; i<n; i++){
    int dst = max(abs(x - v[i].ff), abs(y - v[i].ss));
    if(dst != d[i]) ok = false;
  }
  if((x+y)%2) ok = false;
  return ok;
}
 
int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> v[i].ff >> v[i].ss >> d[i];
    v[i] = convert(v[i].ff, v[i].ss);
  }
  int xl = (int)-1e9, yr = (int)1e9, xr = (int)1e9, yl = (int)-1e9;
  for(int i=0; i<n; i++){
    int xmin = v[i].ff - d[i];
    int xmax = v[i].ff + d[i];
    int ymin = v[i].ss - d[i];
    int ymax = v[i].ss + d[i];
    //intersection
    xl = max(xl, xmin);
    yl = max(yl, ymin);
    xr = min(xr, xmax);
    yr = min(yr, ymax);
  }
  
  set< ii > s;
  if(check(xl, yl)){
    s.insert(ii(xl, yl));
  }
  if(check(xl, yr)){
    s.insert(ii(xl, yr));
  }
  if(check(xr, yl)){
    s.insert(ii(xr, yl));
  }
  if(check(xr, yr)){
    s.insert(ii(xr, yr));
  }
  if(s.size() == 0) cout << "impossible" << endl;
  else if(s.size() > 1) cout << "uncertain" << endl;
  else {
    ii ans = inverse(s.begin()->ff, s.begin()->ss);
    cout << ans.ff << " " << ans.ss << endl;
  } 
}
 
