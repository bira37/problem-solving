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
 
int spt[212345][22];
int e[212345];
 
void build(int *a, int n) {
    for(int i = 0; i < n; i++) {
        spt[i][0] = a[i];
    }
 
    for(int i = 1; (1<<i) <= n; i++) {
        for(int j = 0; j+(1<<i) <= n; j++) {
            spt[j][i] = min(spt[j][i-1], spt[j+(1<<(i-1))][i-1]);
        }
    }
 
    int k = 0;
    for(int j = 0; (1<<j) <= 2*n; j++) {
        for(; k <= n && k < (1<<j); k++) {
            e[k] = j-1;
        }
    }
}
 
int rmq(int l, int r) {
    int sz = (r-l+1);
    return min(spt[l][e[sz]], spt[r-(1<<e[sz])+1][e[sz]]);
}
 
  
int32_t main(){
  DESYNC;
  int n,k;
  cin >> n >> k;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  build(v, n);
  while(k--){
    int val, l, r;
    cin >> val >> l >> r;
    l--, r--;
    int cur = l-1;
    
    while(cur < r){
      int lo = cur+1, hi = r;
      int ans = cur;
      while(lo <= hi){
        int m = (lo+hi)>>1;
        if(rmq(lo, m) <= val){
          ans = m;
          hi = m-1;
        }
        else lo = m+1;
      }
      if(ans == cur) break;
      val %= v[ans];
      cur = ans;
    }
    cout << val << endl;
  }
}
 
