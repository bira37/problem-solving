#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<long long, int>
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
 
struct ConvexHullTrick {
  //max cht, suppose lines are added in crescent order of a  
  ConvexHullTrick() {}
  struct line{
    int id, a, b;
    line() {}
    line(int id, int a, int b) : id(id), a(a), b(b) {}
  };
  bool remove(line & a, line & b, line & c){
    if((a.a - c.a)*(c.b - b.b) <= (b.a - c.a)*(c.b - a.b)) return true;
    else return false;
  }
  vector<line> cht; 
  void add(line & v){
    if(cht.empty()){
      cht.push_back(v);
    }
    else {
      if(cht.back().a == v.a) return;
      while(cht.size() > 1 && remove(cht[cht.size()-2], cht.back(), v)){
        cht.pop_back();
      }
      cht.push_back(v);
    }
  }
 
  void preprocess_cht(vector< line > & v){
    sort(v.begin(), v.end(), [](const line & a, const line & b){
      return (a.a < b.a || (a.a == b.a && a.b > b.b));
    });
    cht.clear();
    for(int i=0; i<v.size(); i++){
      add(v[i]);
    }
  }
 
  int f(int i, int x){
    return cht[i].a*x + cht[i].b;
  }
  
  //return line index
  ii query(int x){
    if(cht.size() == 0) return ii(-INF,-INF);
    if(cht.size() == 1) return ii(f(0, x), cht[0].id);
    int l = 0, r = cht.size()-2;
    int ans= cht.size()-1;
    while(l <= r){
      int m = (l+r)/2;
      int y1 = f(m, x);
      int y2 = f(m+1, x);
      if(y1 >= y2){
        ans = m;
        r = m-1;
      }
      else l = m+1;
    }
    return ii(f(ans, x), cht[ans].id);
  }
 
};
 
ConvexHullTrick st[412345];
vector<ConvexHullTrick::line> lines[412345];
 
void update(int cur, int l, int r, int x, ConvexHullTrick::line ln){
  lines[cur].pb(ln);
  if(l == r) return;
  int m = (l+r)>>1;
  if(x <= m) update(2*cur, l, m, x, ln);
  else update(2*cur+1, m+1, r, x, ln);
}
 
ii query(int cur, int l, int r, int a, int b, int t){
  if(b < l || r < a) return ii(-INF, -INF);
  if(a <= l && r <= b){
    return st[cur].query(t);
  }
  int m = (l+r)>>1;
  ii lef = query(2*cur, l, m, a, b, t);
  ii rig = query(2*cur+1, m+1, r, a, b, t);
  return max(lef, rig);
} 
     
void build(int cur, int l, int r){
  st[cur].preprocess_cht(lines[cur]);
  if(l == r) return;
  int m = (l+r)>>1;
  build(2*cur, l, m);
  build(2*cur+1, m+1, r);
}
 
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  for(int i=0; i<n; i++){
    int a ,b;
    cin >> b >> a;
    update(1, 1, n, i+1, ConvexHullTrick::line(i+1, a,b));
  }
  build(1, 1, n);
  while(q--){
    int l, r, t;
    cin >> l >> r >> t;
    cout << query(1, 1, n, l, r, t).ss << endl;
  }
}
 
