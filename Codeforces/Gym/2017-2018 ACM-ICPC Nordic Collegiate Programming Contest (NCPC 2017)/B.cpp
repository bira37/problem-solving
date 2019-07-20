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
 
struct runner{
  string name;
  double ff, ss;
  runner(){}
  runner(string name, double ff, double ss) : name(name), ff(ff), ss(ss) {}
  bool operator<(const runner & b) const {
    return ss < b.ss;
  }
};
 
int32_t main(){
  //DESYNC;
  int n;
  cin >> n;
  runner v[n];
  for(int i=0; i<n; i++) cin >> v[i].name >> v[i].ff >> v[i].ss;
  vector<string> ans;
  double best = 112345.0;
  for(int i=0; i<n; i++){
    vector< runner > cur;
    vector< string > cur_ans;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      cur.pb(v[j]);
    }
    sort(cur.begin(), cur.end());
    double dist = v[i].ff;
    cur_ans.pb(v[i].name);
    for(int j=0; j<3; j++){
      dist += cur[j].ss;
      cur_ans.pb(cur[j].name);
    }
    if(dist < best){
      best = dist;
      ans = cur_ans;
    }
  }
  cout << best << endl;
  cout << fixed << setprecision(4) << ans[0] << endl << ans[1] << endl << ans[2] << endl << ans[3] << endl; 
}
 
