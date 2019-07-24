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
#define INF 2e17
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
  int n;
  cin >> n;
  vector<ii> v(n+1);
  for(int i=1; i<=n; i++){
    cin >> v[i].ss >> v[i].ff;
  }
  sort(v.begin()+1, v.end());
  set<int> pq;
  map<int,int> cnt;
  int dp[n+1];
  int dp2[n+1];
  multiset< tuple<int,int,int> > wait;
  int mn = INF;
  for(int i=1; i<=n; i++){
    while(wait.size() > 0 and get<0>(*wait.begin()) <= v[i].ff){
      int out, val, count;
      tie(out, val, count) = *wait.begin();
      cnt[val] = mod(cnt[val] + count, M);
      pq.insert(val);
      wait.erase(wait.begin());
    }
    if(pq.size() == 0){
      dp[i] = v[i].ff;
      dp2[i] = 1;
    }
    else {
      dp[i] = *pq.begin() + v[i].ff;
      dp2[i] = cnt[*pq.begin()];
    }
    wait.insert(mt(v[i].ss, dp[i] - v[i].ss, dp2[i]));
    //cout << v[i].ff << " " << v[i].ss << " " << dp[i] << " " << dp2[i] << endl;
  }
  multiset<int, greater<int> > s;
  int ans = 0;
  for(int i=1; i<=n; i++){
    s.insert(v[i].ff);
  }
  for(int i=1; i<=n; i++){
    s.erase(s.find(v[i].ff));
    if(s.size() == 0 || *s.begin() < v[i].ss) mn = min(mn, dp[i]);
    s.insert(v[i].ff);
  }
  for(int i=1; i<=n; i++){
    s.erase(s.find(v[i].ff));
    if((s.size() == 0 || *s.begin() < v[i].ss) and dp[i] == mn) ans = mod(ans + dp2[i], M);
    s.insert(v[i].ff);
  }
  cout << ans << endl;
}
