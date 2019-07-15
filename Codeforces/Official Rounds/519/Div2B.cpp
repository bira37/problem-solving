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
  int n;
  cin >> n;
  int v[n+1];
  v[0] = 0;
  vector<int> ret;
  for(int i=1; i<=n; i++) cin >> v[i];
  for(int k=1; k<=n; k++){
    int x[k];
    bool valid = true;
    for(int i=0; i<k; i++) x[i] = -INF;
    for(int i=1; i<=n; i++){
      int want = v[i] - v[i-1];
      int idx = (i-1)%k;
      if(x[idx] == -INF) x[idx] = want;
      else if(x[idx] != want){
        valid = false;
        break;
      }
    }
    if(valid) ret.pb(k);
  }
  cout << ret.size() << endl;
  for(int x : ret) cout << x << " ";
  cout << endl;
      
    
}

