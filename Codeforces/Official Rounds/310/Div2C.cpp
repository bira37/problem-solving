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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
	DESYNC;
	int ans = 0;
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
	  int k;
	  cin >> k;
	  int v[k];
	  for(int j=0; j<k; j++) cin >> v[j];
	  int cur = v[0];
	  int idx = k-1;
	  for(int j=1; j<k; j++) if(cur +1 == v[j]){
	    cur = v[j];
	    idx--;
	  }
	  if(v[0] == 1){
	    ans += (idx) + (idx+1);
	    if(v[k-1] == n) ans--;
	  }
	  else{
	    ans += (k-1) + k;
	    if(v[k-1] == n) ans--;
	  }
	}
	cout << ans << endl;
}
