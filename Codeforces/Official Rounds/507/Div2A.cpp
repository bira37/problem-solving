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

int32_t main(){
  DESYNC;
  int n,a,b;
  cin >> n >> a >> b;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  if(n%2 == 0){
    int ans = 0;
    for(int i=0, j = n-1; i<j; i++, j--){
      if(v[i] == 0 && v[j] == 2) ans += a;
      else if(v[i] == 1 && v[j] == 2) ans += b;
      else if(v[i] == 2 && v[j] == 0) ans += a;
      else if(v[i] == 2 && v[j] == 1) ans += b;
      else if(v[i] == 2 && v[j] == 2) ans += 2*min(a,b);
      else if(v[i] != v[j]){
        cout << -1 << endl;
        return 0;
      }
    }
    cout << ans << endl;
  }
  else {
    int ans = 0;
    for(int i=0, j = n-1; i<j; i++, j--){
      if(v[i] == 0 && v[j] == 2) ans += a;
      else if(v[i] == 1 && v[j] == 2) ans += b;
      else if(v[i] == 2 && v[j] == 0) ans += a;
      else if(v[i] == 2 && v[j] == 1) ans += b;
      else if(v[i] == 2 && v[j] == 2) ans += 2*min(a,b);
      else if(v[i] != v[j]){
        cout << -1 << endl;
        return 0;
      }
    }
    int m = n/2;
    if(v[m] == 2) ans += min(a,b);
    cout << ans << endl;
  }
}