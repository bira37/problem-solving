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
  int n,m;
  cin >> n >> m;
  vector<int> A[1123], B[1123];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x;
      cin >> x;
      A[i+j].pb(x);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x;
      cin >> x;
      B[i+j].pb(x);
    }
  }
  bool ok = false;
  for(int i=0; i<1123; i++){
    sort(A[i].begin(), A[i].end());
    sort(B[i].begin(), B[i].end());
    if(A[i] != B[i]) ok = true;
  }
  if(ok) cout << "NO" << endl;
  else cout << "YES" << endl;
}

