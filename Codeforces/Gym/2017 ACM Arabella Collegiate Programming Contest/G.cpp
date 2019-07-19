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
 
int PA(int n){
  return (n*(n+1))/2;
}
 
int32_t main(){
	DESYNC;
	int t;
	cin >> t;
	while(t--){
	  int n,m,k;
	  cin >> n >> m >> k;
	  ii v[k];
	  int ans = 0;
	  for(int i=0; i<k; i++) cin >> v[i].ff >> v[i].ss;
	  for(int msk = 1; msk < (1<<k); msk++){
	    int min_x = 100000, min_y = 100000, max_x  = -1, max_y = -1;
	    for(int i=0; i<k; i++){
	      if(msk & (1<<i)){
	        min_x = min(min_x, v[i].ff);
	        min_y = min(min_y, v[i].ss);
	        max_x = max(max_x, v[i].ff);
	        max_y = max(max_y, v[i].ss);
	      }
	    }
	    int val = 0;
	    val += min_x*min_y*(n-max_x+1)*(m-max_y+1);
	    if(__builtin_popcount(msk)%2 == 1) ans += val;
	    else ans -= val;
	  }
	  cout << PA(n)*PA(m) - ans << endl;
	}
}
 
