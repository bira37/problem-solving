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

int v[112345];
int mul[112345];

int solve(){
  int n,m, q;
  cin >> n >> m >> q;
  for(int i=1; i<=n; i++) v[i] = mul[i] = 0;
  for(int i=0; i<m; i++){
    int x;
    cin >> x;
    v[x]++;
  }
  for(int i=1; i<=n; i++){
    for(int j=i; j<=n; j+=i) mul[i] += v[j];
  }
  int ans = 0;
  while(q--){
    int x;
    cin >> x;
    ans += n/x - mul[x];
  }

  return ans;
}
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  for(int i=0; i<t; i++) cout << "Case #" << i+1 << ": " << solve() << endl;
}



