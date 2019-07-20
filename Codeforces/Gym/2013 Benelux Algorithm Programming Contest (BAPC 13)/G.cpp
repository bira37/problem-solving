#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct circle {
  double x,y,r;
  circle () {}
  circle(double x, double y, double r) : x(x), y(y), r(r) {}
  double dist(circle c){
    return sqrt((x - c.x)*(x - c.x) + (y- c.y)*(y- c.y)) - r - c.r;
  }
};
 
int uf[1123];
double min_x[1123], max_x[1123];
double dist[1123][1123];
circle v[1123]; 
int w;
int n;
 
int find(int u){
  if(u == uf[u]) return u;
  else return uf[u] = find(uf[u]);
}
 
bool merge(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x == y) return false;
  if(rand()%2) swap(x,y);
  uf[y] = x;
  min_x[x] = min(min_x[x], min_x[y]);
  max_x[x] = max(max_x[x], max_x[y]);
  return true;
} 
 
bool check(double d){
  for(int i=0; i<n; i++){
    uf[i] = i;
    min_x[i] = v[i].x-v[i].r;
    max_x[i] = v[i].x+v[i].r;
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(dist[i][j] < d) merge(i,j);
    }
  }
  for(int i=0; i<n; i++){
    int u = find(i);
    if(min_x[u] < d && w - max_x[u] < d) return false;
  }
  return true;
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    cin >> w;
    cin >> n;
    for(int i=0; i<n; i++){
      int x,y,r;
      cin >> x >> y >> r;
      v[i] = circle(x,y,r);
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++) dist[i][j] = v[i].dist(v[j]);
    }
    double l = 0.0, r = w;
    double ans = 0;
    for(int it = 0; it < 80; it++){
      double m = (l+r)/2.;
      if(check(m)){
        ans = m;
        l = m;
      }
      else r = m;
    }
    cout << fixed << setprecision(6) << ans/2. << endl;
  }  
}
 
