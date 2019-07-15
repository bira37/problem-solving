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
  int n, q;
  cin >> n >> q;
  int pot[n+1];
  pot[0] = 1;
  for(int i=1; i<=n; i++){
    pot[i] = mod(pot[i-1]*2LL, M);
  }
  string s;
  cin >> s;
  int p0[n+1], p1[n+1];
  p0[0] = 0;
  p1[1] = 0;
  for(int i=0; i<n; i++){
    p0[i+1] = p0[i] + (s[i] == '0');
    p1[i+1] = p1[i] + (s[i] == '1');
  }
  while(q--){
    int l, r;
    cin >> l >> r;
    int q0 = p0[r] - p0[l-1];
    int poe = mod(pot[r-l+1] -1, M);
    int tira = mod(pot[q0] - 1, M);
    cout << mod(poe - tira, M) << endl;
  }
}

