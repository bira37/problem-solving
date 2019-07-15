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
  int n,rr;
  cin >> n >> rr;
  bool heat[n];
  for(int i=0; i<n; i++) heat[i] = false;
  int v[n];
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    v[i] = x;
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    if(heat[i]) continue;
    int r = min(n-1, i + rr - 1);
    int l = max(0LL, i -rr + 1);
    for(int j = r; j>=l; j--){
      if(v[j] == 1){
        //cout << "light with " << j << endl;
        ans++;
        int l = max(0LL, j-rr+1), r = min(n-1, j + rr-1);
        for(int k = l; k <=r; k++){
          heat[k] = true;
        }
        v[j] = 0;
        break;
      }
    }
  }
  for(int i=0; i<n; i++){
    if(!heat[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
    
}

