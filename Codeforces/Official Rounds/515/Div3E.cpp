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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  int pot[n+1];
  pot[0] = 1;
  for(int i=1; i<n; i++)  pot[i] = mod(pot[i-1]*2LL, M);
  string a,b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int pref[n];
  for(int i=0; i<n; i++){
    pref[i] = 0;
    if(a[i] == '1') pref[i] = pot[i];
    if(i != 0) pref[i] += pref[i-1];
  }
  int ans = 0;
  for(int i=0; i<m; i++){
    if(b[i] == '1') ans = mod(ans + pref[min(i,n-1)], M);
  }
  cout << ans << endl;
}

