#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
  DESYNC;
  
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v , v+n);
  
  int q;
  cin >> q;
  while(q--){
    int r1, r2;
    cin >> r1 >> r2;
    int del = r2 - r1;
    int ans = -1, l = 0, r = n-1;
    while(l <= r){
      int m = (l+r)>>1;
      if(v[m] <= del){
        ans = m;
        l = m+1;
      }
      else r = m-1;
    }
    int best = 0;
    int idx = -1;
    if(ans >= 0 && abs((r2-best) - r1) > abs((r2 - v[ans]) - r1) && r2-v[ans] > 0){
      best = v[ans];
      idx = ans;
    }
    if(ans+1 >= 0 && abs((r2-best) - r1) > abs((r2 - v[ans+1]) - r1) && r2-v[ans+1] > 0){
      best = v[ans+1];
      idx = ans+1;
    }
    cout << idx+1 << endl;
  }
 
}
