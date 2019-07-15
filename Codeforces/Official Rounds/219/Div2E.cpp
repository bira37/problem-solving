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
  else return __gcd(a,b);
}

struct firework{
  int a,b,t;
  firework() {}
  firework(int a, int b, int t) : a(a), b(b), t(t) {}
};

deque< ii > dq;

void insert(ii a){
  while(dq.size() > 0 && dq.back().ff < a.ff) dq.pop_back();
  dq.push_back(a);
}

int extract(int x){
  while(dq.size() > 0 && dq.front().ss < x) dq.pop_front();
  return dq.front().ff;
}

int dp[2][150000];

int32_t main(){
	DESYNC;
	int n,m,d;
	cin >> n >> m >> d;
	for(int i=0; i<n; i++) dp[0][i] = 0;
	int lt = 0;
	for(int i=1; i<=m; i++){
	  int a,b,t;
	  cin >> a >> b >> t;
	  a--;
	  dq.clear();
	  int dt = (t - lt)*d;
	  lt = t; 
	  for(int j=0; j<=min(dt, n-1); j++){
	    insert(ii(dp[(i-1)%2][j], j));
	  }
	  dp[i%2][0] = b + extract(0) - abs(a);
	  for(int j=1; j<n; j++){
	    if(j+dt < n) insert(ii(dp[(i-1)%2][j+dt], j+dt));
	    dp[i%2][j] = b + extract(j-dt) - abs(a - j);
	  }
	}
	int ans = -INF;
	/*for(int i=0; i<=m; i++){
	  for(int j=0; j<n; j++) cout << dp[i][j] << " ";
	  cout << endl;
	}*/
	for(int i=0; i<n; i++) ans = max(ans, dp[m%2][i]);
	cout << ans << endl;
}