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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int dp[20][(1<<20)];
bool mat[20][20];
int n;

int solve(int i, int top){
  if(i == n) return 1;
  if(dp[i][top] != -1) return dp[i][top];
  
  int ret = 0;
  
  for(int j=0; j<n; j++){
    if(mat[i][j] && !((1LL<<j) & top)){
      ret += solve(i+1, top | (1LL<<j));
    }
  }
  
  dp[i][top] = ret;
  return ret;
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++) cin >> mat[i][j];
    }
    cout << solve(0, 0) << endl;
  }    
}


