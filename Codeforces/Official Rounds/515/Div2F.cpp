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

int dist(ii a, ii b){
  return abs(a.ff - b.ff) + abs(a.ss-b.ss);
}

int32_t main(){
  DESYNC;
  map<int, vector< ii > > level;
  level[0].pb(ii(0,0));
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    level[max(a,b)].pb(ii(a,b));
  }
  for(auto & it: level){
    sort(it.ss.begin(), it.ss.end(), [](const ii & a, const ii & b){
      return a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss);
    });
  }
  map< ii, int> dp;
  dp[ii(0,0)] = 0;
  dp[ii(0,1)] = 0;
  int last = 0;
  for(auto it : level){
    if(it.ff == 0) continue;
    ii last0 = *level[last].begin();
    ii last1 = *level[last].rbegin();
    int cur = it.ff;
    ii cur0 = *it.ss.begin();
    ii cur1 = *it.ss.rbegin();
    dp[ii(cur, 0)] = min(dp[ii(last, 0)] + dist(last0, cur1) + dist(cur1, cur0), dp[ii(last, 1)] + dist(last1, cur1) + dist(cur1, cur0));
    dp[ii(cur, 1)] = min(dp[ii(last, 0)] + dist(last0, cur0) + dist(cur0, cur1), dp[ii(last, 1)] + dist(last1, cur0) + dist(cur0, cur1));
    last = cur;
  }
  cout << min(dp[ii(last, 0)], dp[ii(last, 1)]) << endl;    
}