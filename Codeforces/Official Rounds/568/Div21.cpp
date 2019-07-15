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

int t[16], g[16];
int T, n;

int dp[(1LL<<15)][4][230];

int go(int msk, int gen, int T){
  if(T == 0) return 1;
  if(dp[msk][gen][T] != -1) return dp[msk][gen][T];
  dp[msk][gen][T] = 0;
  for(int i=0; i<n; i++){
    if((1LL<<i) & msk) continue;
    if(t[i] > T) continue;
    if(g[i] == gen) continue;
    dp[msk][gen][T] = mod(dp[msk][gen][T] + go(msk | (1LL<<i), g[i], T - t[i]), M);
  }
  return dp[msk][gen][T];
}

int32_t main(){
  DESYNC;
  cin >> n >> T;
  memset(dp, -1, sizeof dp);
  for(int i=0; i<n; i++){
    cin >> t[i] >> g[i];
  }
  cout << go(0, 0, T) << endl;
    
}