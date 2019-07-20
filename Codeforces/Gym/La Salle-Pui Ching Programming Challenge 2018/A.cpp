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
  
  int l,r,p;
  cin >> l >> r >> p;
  if(l == r || 100*min(l,r) >= max(l,r)*p) cout << "Ambidextrous" << endl;
  else if(l > r) cout << "Left-handed" << endl;
  else cout << "Right-handed" << endl;
}
