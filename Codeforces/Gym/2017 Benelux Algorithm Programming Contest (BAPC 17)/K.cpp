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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
vector<int> adj[1123];
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j =0; j<n; j++){
      char c;
      cin >> c;
      if(c == '1') adj[i].pb(j);
      else if(c == '0') adj[j].pb(i);
    }
  }
  vector<int> ans;
  ans.pb(0);
  bool vis[n];
  for(int i=0; i<n; i++){
    vis[i] = false;
  }
  vis[0] = true;
  for(int i=0; i<n; i++){
    if(i >= ans.size()) break;
    for(int v : adj[ans[i]]){
      if(vis[v]) continue;
      vis[v] = true;
      ans.pb(v);
    }
  }
  if(ans.size() == n){
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  else cout << "impossible" << endl;
}
 
 
 
 
 
