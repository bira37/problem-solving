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
  int n,m;
  cin >> n >> m;
  int ans = 0;
  vector<int> a(n), b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];
  int x;
  cin >> x;
  vector< ii > v;
  for(int i=0; i<m; i++){
    int sum = 0;
    for(int j = i; j<m; j++){
      sum += b[j];
      v.pb(ii(sum, j-i+1));
    }
  }
  sort(v.begin(), v.end());
  for(int i=1; i<v.size(); i++){
    if(v[i-1].ss > v[i].ss) v[i].ss = v[i-1].ss;
  }
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
      sum += a[j];
      int l = 0, r = v.size()-1;
      int idx = -1;
      while(l<=r){
        int m = (l+r)>>1;
        if(sum*v[m].ff <= x){
          idx = m;
          l = m+1;
        }
        else r = m-1;
      }
      if(idx == -1) continue;
      ans = max(ans, (j-i+1)*v[idx].ss);
    }
  }
  cout << ans << endl; 
}

