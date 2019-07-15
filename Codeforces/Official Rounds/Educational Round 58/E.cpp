#include <bits/stdc++.h>

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
#define INF 1e9+7
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
  int nx = 0, ny = 0;
  while(q--){
    char op;
    cin >> op;
    if(op == '+'){
      int l,r;
      cin >> l >> r;
      if(l > r) swap(l,r);
      nx = max(nx, l);
      ny = max(ny, r);
    }
    else {
      int h,w;
      cin >> h >> w;
      if(h > w) swap(h,w);
      if(nx <= h && ny <= w) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}

