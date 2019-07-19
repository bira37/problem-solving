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
 
int count(int n){
  if(n == 0) return 1;
  if(n == 1) return 1;
  int f[n+1];
  f[0] = 1;
  f[1] = 1;
  for(int i=2; i<=n; i++) f[i] = f[i-1] + f[i-2];
  return f[n];
}
 
vector<int> solve(int n, int k){
  if(n == 0) return vector<int>();
  if(count(n-1) >= k){
    vector<int> ans = solve(n-1, k);
    vector<int> ret;
    ret.pb(1);
    for(int x : ans) ret.pb(x+1);
    return ret;
  }
  else {
    vector<int> ans = solve(n-2, k - count(n-1));
    vector<int> ret;
    ret.pb(2);
    ret.pb(1);
    for(int x : ans) ret.pb(x+2);
    return ret;
  }
}
 
int32_t main(){
	DESYNC;
	int n,k;
	cin >> n >> k;
	vector<int> ans = solve(n,k);
	for(int x : ans) cout << x << " ";
	cout << endl;
}
 
