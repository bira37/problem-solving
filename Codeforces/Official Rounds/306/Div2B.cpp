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
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int n,l,r,x;
int ans = 0;
vector<int> a;
int v[15];
 
void solve(int i, int n){
  if(i == n){
    if(a.size() < 2) return;
    vector<int> b;
    for(int x : a) b.push_back(x);
    sort(b.begin(), b.end());
    int sum = 0;
    for(int x : b) sum += x;
    if(sum < l || r < sum) return;
    if(b.back() - b.front() < x) return;
    ans++;
    return;
  }
  //choose i
  a.push_back(v[i]);
  solve(i+1, n);
  a.pop_back();
  //not choose i
  solve(i+1, n);
}
      
int32_t main(){
	DESYNC;
  cin >> n >> l >> r >> x;
  for(int i=0; i<n; i++) cin >> v[i];
  solve(0, n);
  cout << ans << endl;
}
 
