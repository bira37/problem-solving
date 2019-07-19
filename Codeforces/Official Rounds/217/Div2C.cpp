#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
int f[1123];
 
bool cmp(int x, int y){
  return f[x] > f[y] || (f[x] == f[y] && x < y);
}
 
int32_t main(){
  DESYNC;
  int n,k;
  cin >> n >> k;
  vector<int> v;
  for(int i=0; i<=k; i++) f[i] = 0;
  vector< ii > ans;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    v.pb(x);
    f[x]++;
  }
  sort(v.begin(), v.end(), cmp);
  for(int i =0; i<v.size(); i++) ans.pb(ii(v[i],v[(i+f[v[0]])%n]));
  int cnt = 0;
  for(ii x : ans) cnt += (x.ff != x.ss);
  cout << cnt << endl;
  for(ii x : ans) cout << x.ff << " " << x.ss << endl;
}
