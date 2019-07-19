#include <bits/stdc++.h>

#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF (int)2e9
#define ROOT 1

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
int v[112345];
int sp[22][112345];
int pot[112345];

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  int k = 0;
  for(int j = 0; (1<<j) <= 212345; j++) {
      for(; k <= 112344 && k < (1<<j); k++) {
          pot[k] = j-1;
      }
  }
   
  int scen = 0;
  while(t--){
    cout << "Scenario #" << ++scen << ": " << endl;
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    for(int i=0; i<n; i++){
      sp[0][i] = v[i];
    }
    for(int i = 1; (1<<i) <= n; i++) {
        for(int j = 0; j+(1<<i) <= n; j++) {
            sp[i][j] = min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
        }
    }
    while(q--){
      int l, r;
      cin >> l >> r;
      l--, r--;
      int ans = min(sp[pot[r-l+1]][l], sp[pot[r-l+1]][r-(1<<pot[r-l+1])+1]);
      cout << ans << endl;
    }
  }
} 


