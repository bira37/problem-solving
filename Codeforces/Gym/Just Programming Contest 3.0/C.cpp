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
 
struct talent{
  int a,b;
  talent() {}
  talent(int a, int b) : a(a), b(b) {}
  bool operator<(const talent & t){
    return b > t.b;
  }
};
 
struct warrior{
  int c,d;
  warrior() {}
  warrior(int c, int d) : c(c), d(d) {}
  bool operator<(const warrior & w){
    return d < w.d;
  }
};
 
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n, m, k;
    cin >> n >> m >> k;
    int cast, mana;
    cin >> cast >> mana;
    talent t[m];
    warrior w[k];
    for(int i=0; i<m; i++) cin >> t[i].a;
    for(int i=0; i<m; i++) cin >> t[i].b;
    for(int i=0; i<k; i++) cin >> w[i].c;
    for(int i=0; i<k; i++) cin >> w[i].d;
    sort(t, t+m);
    sort(w, w+k);
    int ans = n*cast;
    for(int i=0; i<k; i++){
      if(w[i].d > mana) continue;
      int cur = max(0LL, n - w[i].c);
      ans = min(ans, cast*cur);
    }
    int mx = 0;
    int pt = 0;
    for(int i=0; i<m; i++){
      //check alone
      if(t[i].b > mana) continue;
      ans = min(ans, n*t[i].a);
      
      //check using two
      int cur_mana = mana - t[i].b;
      while(pt < k && w[pt].d <= cur_mana){
        mx = max(mx, w[pt].c);
        pt++;
      }
      int cur = max(0LL, n - mx);
      ans = min(ans, cur*t[i].a);
    }
    cout << ans << endl;
  }    
}
 
