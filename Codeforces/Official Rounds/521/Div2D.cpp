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

int n,k;
int v[212345];
vector<ii> a;
vector<int> ans;

bool check(int t){
  ans.clear();
  for(ii el : a){
    int cnt = el.ss;
    while(cnt >= t){
      ans.pb(el.ff);
      cnt -= t;
    }
  }
  if(ans.size() >= k) return true;
  else return false;
}

int32_t main(){
  DESYNC;
  cin >> n >> k;
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v, v+n);
  for(int i=0; i<n; i++){
    if(a.size() == 0 || a.back().ff != v[i]) a.pb(ii(v[i], 1));
    else a.back().ss++;
  }
  int l = 1, r = n;
  int good = -1;
  while(l <=r){
    int m = (l+r)>>1;
    if(check(m)){
      good = m;
      l = m+1;
    }
    else r = m-1;
  }
  check(good);
  for(int i=0; i<k; i++) cout << ans[i] << " ";
  cout << endl;
}

