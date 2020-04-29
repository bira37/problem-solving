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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int exp(int a, int k){
  if(k == 0) return 1LL;
  if(k == 1) return a;
  int ax = exp(a, k/2);
  ax = mod(ax*ax, M);
  if(k%2) ax = mod(ax*a, M);
  return ax;
}

int fat[212345], inv[212345];

int finv(int n){
  return exp(n, M-2);
}

int C(int n, int k){
  int num = fat[n];
  int den = mod(inv[k]*inv[n-k], M);
  return mod(num*den, M);
}

int32_t main(){
  DESYNC;
  fat[0] = 1;
  inv[0] = 1;
  int n,k;
  cin >> n >> k;
  if(k > n-1){
    cout << 0 << endl;
    return 0;
  }
  for(int i=1; i<=n; i++){
    fat[i] = mod(fat[i-1]*i, M);
    inv[i] = finv(fat[i]);
  }
  
  int c = n-k;
  
  int ans = 0;
  
  for(int i=0; i<=c; i++){
    if(i%2) {
      ans = mod(ans - C(c, i)*exp(c - i, n), M);
    }
    else ans = mod(ans + C(c, i)*exp(c - i, n), M);  
  }
  
  ans = mod(ans*C(n, c), M);
  if(k > 0) ans = mod(ans*2LL, M);
  
  cout << ans << endl;
}


