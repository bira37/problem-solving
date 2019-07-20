#include <bits/stdc++.h>
 
#define int long long
#define double long double
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
 
int dp[112][112][2][2];
 
int DP(int p, int q, int s, int j) {
  if(dp[p][q][s][j] != -INF) return dp[p][q][s][j];
  if(p == 0 || q == 0){
    dp[p][q][s][j] = 0;
    return dp[p][q][s][j];
  }
  
  if(j == 0) {
    int best = -INF;
    for(int i = 1; i <= q; i++) {
      int aux = 0;
      if(s==0 && p%2 && i%2) aux = 1;
      if(s==1 && p%2 && i%2) aux = -1;
      best = max(best, DP(p, q-i, i%2 ? s^1 : s, j^1)+aux);
    }
    dp[p][q][s][j] = best;
  } else {
    int best = INF;
    for(int i = 1; i <= p; i++) {
      int aux = 0;
      if(((s==0&&p%2)||(s==1&&p%2==0)) && q%2 && i%2) aux = 1;
      if(((s==1&&p%2)||(s==0&&p%2==0)) && q%2 && i%2) aux = -1;
      best = min(best, DP(p-i, q, s, j^1)-aux);
    }
    dp[p][q][s][j] = best;
  }
  return dp[p][q][s][j];
}
 
int32_t main(){
	DESYNC;
	int p,q;
	cin >> p >> q;
	
	for(int i=0; i<112; i++){
	  for(int j=0; j<112; j++){
	    for(int k=0; k<2; k++){
	      for(int l = 0; l < 2; l++) dp[i][j][k][l] = -INF;
	    }
	  }
	}
  cout << DP(p, q, 0, 0) << endl;
}
 
