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

int dp[112345];
int v[112345];
int n;

int solve(int id){
  if(dp[id] != -1) return dp[id];
  
  int x = v[id];
  dp[id] = 0;
  for(int i = id+x; i < n; i+= x){
    if(v[i] < v[id]) continue;
    if(solve(i) == 0){
      dp[id] = 1;
      break;
    }
  }
  for(int i = id-x; i >= 0; i-= x){
    if(v[i] < v[id]) continue;
    if(solve(i) == 0){
      dp[id] = 1;
      break;
    }
  }
  //cout << "dp[" << id << "] // " << v[id] << " = " << dp[id] << endl;
  return dp[id];
}

int32_t main(){
  DESYNC;
  cin >> n;
  char ans[n+1];
  for(int i=0; i<n; i++){
    cin >> v[i];
    dp[i] = -1;
  }
  for(int i=0; i<n; i++){
    if(solve(i) == 0) cout << 'B';
    else cout << 'A';
  }
  //for(int i=1; i<=n; i++) cout << ans[i];
  cout << endl;
}

