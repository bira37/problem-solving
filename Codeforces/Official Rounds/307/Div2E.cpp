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
 
vector< ii > b[1000];
int lazy[1000] = {0};
int v[512345];
int sqr = 710;
int n,q;
 
void update(int l, int r, int x){
  int lb = l/sqr + 1;
  int rb = r/sqr - 1;
  for(ii & e : b[l/sqr]){
    if(e.second >= l && e.second <= r) e.first += x;
  }
  if(r/sqr != l/sqr) for(ii & e : b[r/sqr]){
    if(e.second >= l && e.second <= r) e.first += x;
  }
  sort(b[l/sqr].begin(), b[l/sqr].end());
  sort(b[r/sqr].begin(), b[r/sqr].end());
  for(int i = lb; i<=rb; i++) lazy[i] += x;
}
 
int get_min(int bl, int x){
  int l = 0, r = b[bl].size()-1;
  //cout << "getting " << x << endl;
  int ans = 612345;
  while(l <= r){
    int m = (l+r)>>1;
    if(b[bl][m].first >= x){
      if(b[bl][m].first == x) ans = min(ans, b[bl][m].second);
      r = m-1;
    }
    else l = m + 1;
  }
  return ans;
}
 
int get_max(int bl, int x){
  int l = 0, r = b[bl].size()-1;
  //cout << "getting " << x << endl;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(b[bl][m].first <= x){
      if(b[bl][m].first == x) ans = max(ans, b[bl][m].second);
      l = m + 1;
    }
    else r = m-1;
  }
  return ans;
}
 
int query(int x){
  int lb = 0;
  int rb = (n-1)/sqr; 
  int left = 612345, right = -1;
  for(int i = lb; i<=rb; i++){
    left = min(left, get_min(i, x - lazy[i]));
    right = max(right, get_max(i, x - lazy[i]));
  }
  //cout << "l/r " << left << "/" << right << endl;
  if(right == -1) return -1;
  else return (right - left);
}
 
int32_t main(){
	DESYNC;
	cin >> n >> q;
	for(int i=0; i<n; i++){
	  int x;
	  cin >> x;
	  b[i/sqr].pb(ii(x, i));
	}
	for(int i=0; i<=(n-1)/sqr; i++){
	  sort(b[i].begin(), b[i].end());
	}
	while(q--){
	  int t;
	  cin >> t;
	  if(t == 1){
	    int l,r,x;
	    cin >> l >> r >> x;
	    l--, r--;
	    update(l, r, x);
	  }
	  else {
	    int x;
	    cin >> x;
	    cout << query(x) << endl;
	  }
	  /*for(int i = 0; i<=(n-1)/sqr; i++){
	    cout << "block " << i << endl;
	    for(ii x : b[i]) cout << "(" << x.first << "," << x.second << ") ";
	    cout << endl;
	  }*/
	}
}
 
