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
  int b[n], g[m];
  int ans = 0;
  for(int i=0; i<n; i++){
    cin >> b[i];
    ans += b[i];
  }
  ans *= m;
  for(int i=0; i<m; i++) cin >> g[i];
  set<ii> s;
  sort(g, g+m);
  sort(b, b+n);
  if(g[0] < b[n-1]){
    cout << -1 << endl;
    return 0;
  }
  int cnt[n];
  for(int i=0; i<n; i++){
    cnt[i] = 0;
  }
  for(int i=0; i<m; i++){
    int l = 0, r = n-1;
    int idx = -1;
    while(l <= r){
      int mid = (l+r)>>1;
      if(b[mid] > g[i]){
        r = mid-1;
      }
      else {
        idx = mid;
        l = mid+1;
      }
    }
    while(idx >= 0 && cnt[idx] >= m-1){
      idx--;
    }
    if(idx == -1){
      cout << -1 << endl;
      return 0;
    }
    if(g[i] > b[idx]) cnt[idx]++;
    //cout << g[i] << " " << idx << " " << b[idx] << endl;
    ans += (g[i] - b[idx]);
  }
  cout << ans << endl;  
}

