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

/* Change the output to pass F1 */
int32_t main(){
  DESYNC;
  int n,r;
  cin >> n >> r;
  vector< ii > v, w;
  for(int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    if(b >= 0) w.pb(ii(a,b));
    else v.pb(ii(a,b));
  }
  sort(w.begin(), w.end());
  int can = 0;
  for(ii x : w){
    if(x.ff <= r){
      r += x.ss;
      can++;
    }
  }
  auto comp = [](const ii & a, const ii & b){
    return a.ff + a.ss > b.ff + b.ss;
  };
  
  sort(v.begin(), v.end(), comp);
  
  int dp[v.size()+10];
  for(int i=0; i<v.size()+10; i++) dp[i] = -INF;
  int mx = 0;
  dp[0] = r;
  for(ii x : v){
    for(int j = mx; j >= 0; j--){
      if(dp[j] >= x.ff and dp[j]+x.ss >= 0){
        dp[j+1] = max(dp[j+1], dp[j]+x.ss);
        mx = max(mx, j+1);
      }
    }
  }
  /* F1 Output 
  if(mx + can == n) cout << "YES" << endl;
  else cout << "NO" << endl; */
  cout << mx + can << endl;
}
