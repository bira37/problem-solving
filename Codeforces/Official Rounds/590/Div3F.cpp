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
 
bool vis[(1LL<<20)];
int mx[(1LL<<20)];
 
int solve(int msk){
  if(msk == 0) return 0;
  if(vis[msk]) return mx[msk];
  vis[msk] = true;
  for(int i=0; i<20; i++){
    if((1LL<<i) & msk){
      mx[msk] = max(mx[msk], solve(msk ^ (1<<i)));
    }
  }
  return mx[msk];
}
 
int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0; i<n; i++){
    int msk = 0;
    for(int j=i; j<n; j++){
      int val = (msk & (1LL<<(s[j]-'a')));
      if(val != 0) break;
      msk |= (1LL<<(s[j]-'a'));
      mx[msk] = max(mx[msk], j-i+1);
    }
  }
  for(int i=0; i<(1LL<<20); i++){
    solve(i);
  }
  int ans = 0;
  for(int i=0; i<(1LL<<20); i++){
    ans = max(ans, mx[i] + mx[i ^ ((1LL<<20)-1LL)]);
  }
  cout << ans << endl;
}
