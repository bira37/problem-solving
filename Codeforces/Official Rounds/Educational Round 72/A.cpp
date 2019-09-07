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
    int s,i,e;
    cin >> s >> i >> e;
    int tira = min((i-s)+1, e);
    if(tira < 0) tira = 0;
    e -= tira;
    s += tira;
    if(e == 0 and s <= i){
      cout << 0 << endl;
    }
    else {  
      int ans = 0;
      int l = 0, r = e;
      while(l <= r){
        int m = (l+r)>>1;
        //cout << "try " << m << " " << s-i << " " << (e - m) - m << endl;
        if((s-i) > (e - m) - m){
          ans = m;
          r = m-1;
        }
        else l = m +1;
      }
      cout << e - ans+1 << endl;
    }
  }
    
}
