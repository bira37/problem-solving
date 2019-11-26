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
  int n, k;
  cin >> n >> k;
  int v[n+1];
  for(int i=1; i<=n; i++) cin >> v[i];
  int p[n+1];
  p[0] = 0;
  for(int i=1; i<=n; i++){
    p[i] = p[i-1] + v[i];
  }
  map<int,int> m;
  m[p[0] - 0]++;
  int ans = 0;
  for(int i = 1; i<=n; i++){
    if(i - k >= 0){
      int x = p[i-k] - (i-k);
      x %= k;
      m[x]--;
    }
    int val = p[i] - i;
    val %= k;
    //cout << i << "= " << val << endl;
    //cout << "ans bef = " << ans << endl;
    ans += m[val];
    //cout << "ans after = " << ans << endl;
    m[val]++;
  }
  cout << ans << endl;
}



