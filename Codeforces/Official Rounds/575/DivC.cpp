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
 
int32_t main(){
  DESYNC;
  int q;
  cin >> q;
  while(q--){
    int lx = -100000, ly = -100000, rx = 100000, ry = 100000;
    
    int n;
    cin >> n;
    while(n--){
      int x,y,lef, up,rig, down;
      cin >> x >> y >> lef >> up >> rig >> down;
      int a = x, b = y, c = x, d = y;
      if(lef) a = -100000;
      if(rig) c = 100000;
      if(up) d = 100000;
      if(down) b = -100000;
      lx = max(lx, a);
      ly = max(ly, b);
      rx = min(rx, c);
      ry = min(ry, d);
    }
    if(lx <= rx and ly <= ry){
      cout << 1 << " " << lx << " " << ly << endl;
    }
    else cout << 0 << endl;
  }
}
 
