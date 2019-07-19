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
 
int n,x;
int v[112345];
 
bool check(int k){
  int r = 0;
  int a[n];
  for(int i=0; i<n; i++) a[i] = v[i];
  
  for(int i=0; i<x; i++){
    int cur = r+1;
    while(r < n && cur < k){
      while(r < n && cur < k && a[r] == 0){
        r++;
        cur++;
      }
      //cout << "guy " << i << " at " << r << " " << a[r] << " " << cur << endl;
      if(r == n) break;
      if(cur == k) break;
      int tira = min(a[r], k - cur);
      a[r] -= tira;
      cur += tira;
    }
  }
  while(r < n && a[r] == 0) r++;
  return r == n;
}
 
int32_t main(){
	DESYNC;
  cin >> n >> x;
  for(int i=0; i<n; i++) cin >> v[i];
  int l = 0, r = (int)1e18;
  int ans = -1;
  while(l <= r){
    int m =(l+r)>>1;
    if(check(m)){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  cout << ans << endl;	
}
	      
	  
