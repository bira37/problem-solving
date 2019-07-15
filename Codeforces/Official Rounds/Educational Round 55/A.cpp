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
  int t;
  cin >> t;
  while(t--){
    int n,x,y,d;
    cin >> n >> x >> y >> d;
    int ans = INF;
    if(abs(x-y)%d == 0) ans = min(ans, abs(x-y)/d);
    if(abs(y-1)%d == 0) ans = min(ans, abs(y-1)/d + (abs(x-1)+d-1)/d);
    if(abs(y-n)%d == 0) ans = min(ans, abs(y-n)/d + (abs(x-n)+d-1)/d);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
  }
  
}

