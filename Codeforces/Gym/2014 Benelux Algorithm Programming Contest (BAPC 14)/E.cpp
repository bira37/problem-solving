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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int st[4*112345];
 
void update(int cur, int l, int r, int id, int x){
  if(l == r){
    st[cur] = x;
    return;
  }
  int m = (l+r)>>1;
  if(id <= m) update(2*cur, l, m, id, x);
  else update(2*cur+1, m+1, r, id, x);
  
  st[cur] = min(st[2*cur], st[2*cur+1]);
}
 
int query(int cur, int l, int r, int a, int b){
  if(b < l || r < a) return INF;
  if(a <= l && r <= b) return st[cur];
  int m = (l+r)>>1;
  int lef = query(2*cur, l, m, a , b);
  int rig = query(2*cur+1, m+1, r, a, b);
  return min(lef, rig);
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0; i<=4*n; i++) st[i] = INF;
    tuple<int,int,int> v[n];
    for(int i=0; i<n; i++){
      int x,y,z;
      cin >> x >> y >> z;
      v[i] = make_tuple(x,y,z);
    }
    sort(v, v+n);
    int ans = 0;
    for(int i=0; i<n; i++){
      int x,y,z;
      tie(x,y,z) = v[i];
      if(query(1, 1, n, 1, y-1) >=  z) ans++;
      update(1, 1, n, y, z);
    }
    cout << ans << endl;
  }
}
 
