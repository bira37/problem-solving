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

double dp[2005][2005][2][2];
int tl[2005], tr[2005];
int t[2005];
int n,h;
double p;

double solve(int i, int j, bool left, bool right){
  if(i > j) return 0;
  if(dp[i][j][left][right] >= 0) return dp[i][j][left][right];
  
  int lb = t[i-1] + (left ? h : 0);
  int rb = t[j+1] - (right ? h : 0);
  
  double ans = 0;
  
  int r = min(tr[i], j);
  //i-th tree falls to the right
  ans += 0.5*(1-p)*( (min(t[r]+h, rb) - t[i]) + solve(r+1, j, 1, right) );
  //i-th tree falls to the left
  ans += 0.5*p*( (t[i] - max(t[i]-h, lb)) + solve(i+1, j, 0, right) );
  
  int l = max(tl[j], i);
  //j-th tree falls to the right
  ans += 0.5*(1-p)*( (min(t[j]+h, rb) - t[j]) + solve(i, j-1, left, 0) );
  //j-th tree falls to the left
  ans += 0.5*p*( (t[j] - max(t[l]-h, lb)) + solve(i, l-1, left, 1) );
  
  dp[i][j][left][right] = ans;
  
  return ans;
}

int32_t main(){
	DESYNC;
	cin >> n >> h >> p;
	for(int i=0; i<=n; i++){
	  for(int j=0; j<=n;  j++){
	    for(int k=0; k<2; k++){
	      dp[i][j][k][1] = dp[i][j][k][0] = -1;
	    }
	  }
	}
	
	for(int i=0; i<n; i++) cin >> t[i];
	t[n+1] = INT_MIN;
	t[n] = INT_MAX;
	sort(t, t+n+2);
	
	tl[1] = 1;
	for(int i=2; i<=n; i++){
	  if(t[i]-(h-1) <=  t[i-1]) tl[i] = tl[i-1];
	  else tl[i] = i;
	} 
	tr[n] = n;
	for(int i=n-1; i>=0; i--){
	  if(t[i] + (h-1) >= t[i+1]) tr[i] = tr[i+1];
	  else tr[i] = i;
	}
	
	cout << fixed << setprecision(9) << solve(1, n, 0, 0) << endl;
}