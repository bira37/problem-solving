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
    int b,w;
    cin >> b >> w;
    int tot = b+w;
    vector<ii> ans;
    int x = 100000, y = 100000;
    if(b < w){
      swap(b,w);
      x--;
    }
    for(int i=0; i<w; i++){
      ans.pb(ii(x,y));
      ans.pb(ii(x+1, y));
      x+=2;
    }
    b -= w;
    if(b > 0){
      ans.pb(ii(ans.front().ff-1, y));
      b--;
    }
    if(b > 2*w){
      cout << "NO" << endl;
    }
    else {
      for(int i=0; i<2*w && b > 0; i+=2){
        ans.pb(ii(ans[i].ff, y+1));
        b--;
        if(b > 0){
          ans.pb(ii(ans[i].ff, y-1));
          b--;
        }
      }
      cout << "YES" << endl;
      for(ii p : ans) cout << p.ff << " " << p.ss << endl;
    }
  }
      
    
    
}
 
