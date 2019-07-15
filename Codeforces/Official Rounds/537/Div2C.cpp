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

int n,k,a,b;
vector<int> v;

int go(int l, int r){
  auto lef = lower_bound(v.begin(), v.end(), l);
  auto rig = upper_bound(v.begin(), v.end(), r);
  int av = rig - lef;
  if(l == r){
    if(av > 0) return b*av;
    else return a;
  }
  if(av == 0){
    return a;
  }
  int m = (l+r)/2;
  return min(b*av*(r-l+1), go(l,m) + go(m+1, r));
}

int32_t main(){
  DESYNC;
  cin >> n >> k >> a >> b;
  n = (1LL<<n);
  v.resize(k);
  for(int i=0; i<k; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int ans = go(1, n);
  cout << ans << endl;
}

