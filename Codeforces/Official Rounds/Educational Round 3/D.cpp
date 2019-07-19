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
 
int a[212345];
int b[212345];
int n,m,k,s;
int t[212345];
int c[212345];
 
 
bool check(int d, bool print){
  int pound = INF;
  int dollar = INF;
  int day_dollar = INF;
  int day_pound = INF;
  for(int i=1; i<=d; i++){
    if(b[i] < pound){
      pound = min(pound, b[i]);
      day_pound = i;
    }
    if(a[i] < dollar){
      dollar = min(dollar, a[i]);
      day_dollar = i;
    }
  }
  vector< tuple<int,int,int> > v;
  for(int i=1; i<=m; i++){
    if(t[i] == 1) v.pb(mt(c[i]*dollar, i, day_dollar));
    else if(t[i] == 2) v.pb(mt(c[i]*pound, i, day_pound));
  }
  //cout << "for " << d << " " << dollar << " " << pound << endl;
  sort(v.begin(), v.end());
  vector< ii > ans;
  int cost = 0;
  for(int i=0; i<k; i++){
    cost += get<0>(v[i]);
    if(print) ans.pb(ii(get<1>(v[i]), get<2>(v[i])));
  }
  if(print && cost <= s){
    cout << d << endl;
    for(ii p : ans) cout << p.ff << " " << p.ss << endl;
  }
  //cout << "for " << d << " " << cost << endl;
  return cost <= s;
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m >> k >> s;
  for(int i=1; i<=n; i++){
    cin >> a[i];
  }
  for(int i=1; i<=n; i++){
    cin >> b[i];
  }
  for(int i=1; i<=m; i++){
    cin >> t[i] >> c[i];
  }
  int l = 1, r = n;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m, false)){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  if(ans != -1){
    check(ans, true);
  }
  else cout << ans << endl; 
}
 
