#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
  DESYNC;
  
  int n, k;
  cin >> n >> k;
  
  vector< ii > h(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i].ff >> h[i].ss;
  }
  sort(h.begin(), h.end());
  
  int rem, ans = 0;
  if(h[0].ff < 0) {  
    rem = k;
    ans += -h[0].ff;
    int i;
    for(i = 0; i < n && h[i].ff < 0; i++) {
      if(i) ans += abs(h[i].ff - h[i-1].ff); 
      if(h[i].ss <= rem) {
        rem -= h[i].ss;
        h[i].ss = 0;
      } else {
        h[i].ss -= rem;
        rem = 0;
        int nd = (h[i].ss+k-1)/k;
        ans += nd*abs(h[i].ff)*2;
        rem = (k-(h[i].ss)%k)%k;
      }
    }
    i--;
    if(i>=0) {
      ans += 0-h[i].ff;
    }
  }
  //cout << ans << endl;
  if(h[n-1].ff > 0) {
    rem = k;
    ans += h[n-1].ff;
    //cout << ans << endl;
    int i;
    for(i = n-1; i >= 0 && h[i].ff > 0; i--) {
      if(i<n-1) ans += abs(h[i].ff - h[i+1].ff); 
      //cout << i << " " << rem << " " << h[i].ss << endl;
      if(h[i].ss <= rem) {
        //cout << "bla" << endl;
        rem -= h[i].ss;
        h[i].ss = 0;
      } else {
        h[i].ss -= rem;
        rem = 0;
        int nd = (h[i].ss+k-1)/k;
        ans += nd*abs(h[i].ff)*2;
        rem = (k-(h[i].ss)%k)%k;
      }
      //cout << ans << endl;
    }
    i++;
    if(i<n) {
      ans += h[i].ff;
    }
  }
  
  cout << ans << endl;
  
}
 
