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
 
vector<int> adj[3000];
int n,k;
 
int exp(int a, int k){
  if(k == 0) return 1;
  if(k == 1) return a;
  
  int mx = exp(a, k/2);
  
  mx = mod(mx*mx, M);
  
  if(k%2) mx = mod(mx*a, M);
  
  return mx;
}
 
int fat[3000];
int inv[3000];
 
void precalc(){
  fat[0] = 1;
  inv[0] = 1;
  for(int i=1; i<3000; i++){
    fat[i] = mod(fat[i-1]*i, M);
    inv[i] = exp(fat[i], M-2);
  }
}
 
int C(int n, int k){
  return mod(fat[n] * mod(inv[n-k]*inv[k], M), M);
}  
  
int32_t main(){
  DESYNC;
  precalc();
  cin >> n >> k;
  for(int i=1; i<n; i++){
    int v;
    cin >> v;
    adj[i].pb(v);
    adj[v].pb(i);
  }  
  int ans[k+1];
  
  
  for(int c = 1; c <= k; c++){
    ans[c] = mod(c*exp(c-1, n-1), M);
  }
  
  int uhu = 0;
  for(int c=1; c <= k; c++){
    if((k-c)%2) uhu = mod(uhu - ans[c]*C(k, c), M);
    else uhu = mod(uhu + ans[c]*C(k, c), M);
  }
  cout << uhu << endl;
}
 
