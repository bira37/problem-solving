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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<int, greater<int> > zero;
  int p[n+1];
  int d[n+1];
  for(int i=0; i<=n; i++){
    if(s[i] == '0') zero.insert(i);
    p[i] = -1;
    d[i] = INF;
  }
  set<ii> q;
  q.insert(ii(0, 0));
  d[0] = 0;
  while(!q.empty()){
    int u = q.begin()->ff;
    int dst = q.begin()->ss;
    q.erase(q.begin());
    if(d[u] != dst) continue;
    int cur = u+k+1;
    while(true){
      auto it = zero.upper_bound(cur);
      if(it == zero.end()) break;
      int ad = *it;
      if(ad <= u) break;
      if(ad - u > k) break;
      if(d[ad] <= dst + 1) break;
      if(d[ad] > dst+1){
        //cout << "from " << u << " go to " << ad << endl;
        p[ad] = u;
        d[ad] = dst+1;
        q.insert(ii(ad, d[ad]));
      }
      cur = ad;
    }
  }
  if(d[n] >= INF){
    cout << -1 << endl;
    return 0;
  }
  vector<int> v;
  int cur = n;
  while(cur != -1){
    v.pb(cur);
    cur = p[cur];
  }
  reverse(v.begin(), v.end());
  for(int i=1; i<v.size(); i++){
    if(i > 1) cout << " ";
    cout << v[i] - v[i-1];
  }
  cout << endl;
}



