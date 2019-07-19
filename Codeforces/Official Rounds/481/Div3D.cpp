#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define mt make_tuple
#define mp make_pair
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
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  if(n <= 2){
    cout << 0 << endl;
    return 0;
  }
  int ans = INF;
  for(int x = -1; x <= 1; x++){
    for(int y = -1; y <= 1; y++){
      int a1 = v[0] + x;
      int a2 = v[1] + y;
      int cnt = abs(x) + abs(y);
      bool ok = true;
      for(int i=2; i<n; i++){
        int want = a1 + i*(a2 - a1);
        if(abs(want - v[i]) > 1){
          ok = false;
          break;
        }
        else if(abs(want-v[i]) == 1) cnt++;
      }
      if(ok) ans = min(ans, cnt);
    }
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
}
