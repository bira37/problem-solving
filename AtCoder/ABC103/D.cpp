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

int32_t main(){
	DESYNC;
	int n,m;
	cin >> n >> m;
	int ans = 0;
	vector< ii > v(m);
	for(int i=0; i<m; i++){
	  cin >> v[i].ff >> v[i].ss;
	}
	sort(v.begin(), v.end());
	int l = 0, r = n+1;
	int last_l = 0, last_r = n+1;
	for(int i=0; i<m; i++){
	  l = max(l, v[i].ff);
	  r = min(r, v[i].ss);
	  if(r - l + 1 >= 2){
	    last_l = l;
	    last_r = r;
	  }
	  else {
	    ans++;
	    l = v[i].ff;
	    r = v[i].ss;
	  }
	}
	if(r - l + 1 >= 2) ans++;
	cout << ans << endl;
	  
}


