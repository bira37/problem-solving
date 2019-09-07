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
loop:  while(t--){
    int n, x;
    cin >> n >> x;
    int mega_blow = 0;
    int best_ans = INF;
    int d[n], h[n];
    for(int i=0; i<n; i++){
      cin >> d[i] >> h[i];
      mega_blow = max(d[i], mega_blow);
    }
    x -= mega_blow;
    if(x <= 0){
      cout << 1 << endl;
      goto loop;
    }
    int prt = INF;
    for(int i=0; i<n; i++){
      //checks
      int l = 0, r = x+10;
      int ans = -1;
      while(l <= r){
        int m = (l+r)>>1;
        if((m*d[i] - m*h[i]) >= x){
          ans = m;
          r = m-1;
        }
        else l = m+1;
      }
      if(ans == -1) continue;
      prt = min(prt, ans+1);
    }
    if(prt == INF) prt = -1;
    cout << prt << endl;
  }
}
