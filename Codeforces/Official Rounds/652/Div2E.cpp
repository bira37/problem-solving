#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n,m;
  cin >> n >> m;
  vector<ii> g[n];
  int w[n], qt[n];
  set<int> available;
  rep(i, 0, n, 1) cin >> w[i];
  rep(i, 0, n, 1) qt[i] = 0;
  rep(i, 0, m, 1){
    int x,y;
    cin >> x >> y;
    available.insert(i);
    qt[x-1]++;
    qt[y-1]++;
    g[x-1].pb(ii(y-1, i));
    g[y-1].pb(ii(x-1, i));
  }
  set<ii, greater<ii> > s;
  rep(i, 0, n, 1){
    s.insert(ii(w[i] - qt[i], i));
  }
  vector<int> ans;
  while(s.size() > 0){
    ii cur = *s.begin();
    s.erase(s.begin());
    //cout << "at " << cur.ff << " " << cur.ss << endl;
    if(cur.ff < 0){
      cout << "DEAD" << endl;
      return;
    }
    
    // remove from others
    for(ii x : g[cur.ss]){
      if(!available.count(x.ss)) continue;
      s.erase(ii(w[x.ff] - qt[x.ff], x.ff));
      qt[x.ff]--;
      s.insert(ii(w[x.ff] - qt[x.ff], x.ff));
      ans.pb(x.ss);
      available.erase(x.ss);
    }
  }
  reverse(all(ans));
  cout << "ALIVE" << endl;
  for(int x : ans) cout << x+1 << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}
